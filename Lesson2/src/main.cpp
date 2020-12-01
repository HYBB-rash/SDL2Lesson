//
// Created by hyong on 2020/12/1.
//

#include <iostream>
#include <SDL.h>
#include <string>
#include "res_path.h"
#include "cleanup.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/**
 * 将一些SDL错误记录到我们的信息流里面去
 * @param os 输入流
 * @param msg 错误信息
 */
void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

/**
 * 把BMP格式的图片加载到渲染器中
 * @param file 图片路径
 * @param ren 渲染器
 * @return 返回一个texture
 */
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr) {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == nullptr) logSDLError(std::cout, "CreateTextureFromSurface");
    } else logSDLError(std::cout, "LoadBMP");
    return texture;
}

/**
 *
 * @param tex
 * @param ren
 * @param x
 * @param y
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, nullptr, &dst);
}

int main(int argc, char** argv){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logSDLError(std::cout, "SDL_Init");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
            "Lesson2",
            100, 100,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        logSDLError(std::cout, "CreateWindow");
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        logSDLError(std::cout, "CreateRenderer");
        cleanup(window);
        SDL_Quit();
        return 1;
    }

    const std::string resPath = getResourcePath("Lesson2");
    SDL_Texture *background = loadTexture(resPath + "background.bmp", renderer);
    SDL_Texture *image = loadTexture(resPath + "image.bmp", renderer);
    if (background == nullptr || image == nullptr) {
        cleanup(background, image, renderer, window);
        SDL_Quit();
        return 1;
    }

    SDL_RenderClear(renderer);
    int bW, bH;
    SDL_QueryTexture(background, nullptr, nullptr, &bW, &bH);
    renderTexture(background, renderer, 0, 0);
    renderTexture(background, renderer, bW, 0);
    renderTexture(background, renderer, 0, bH);
    renderTexture(background, renderer, bW, bH);

    int iW, iH;
    SDL_QueryTexture(image, nullptr, nullptr, &iW, &iH);
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;
    renderTexture(image, renderer, x, y);

    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    cleanup(background, image, renderer, window);
    SDL_Quit();

}