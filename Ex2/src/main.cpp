//
// Created by hyong on 12/28/20.
//

#include <iostream>
#include <SDL.h>
#include <cmath>

using namespace std;

int main (int argc, char** argv) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "SDL_Init Error" << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
            "ex2",
            400, 600, 640, 480,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 16);
    SDL_RenderDrawLine(renderer, 240, 180, 400 ,300);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 16);
    SDL_RenderDrawLine(renderer, 400, 180, 240, 300);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 16);
    double r = 15;
    double x = 240, y = 180;
    double x1 = 240, x2 = 0, y1 = y + r, y2 = 0;
    double PI = 3.1415926535;
    for (int i = 0; i < 360; i ++) {
        double dx = sin(i * PI / 180) * r;
        double dy = cos(i * PI / 180) * r;
        x2 = x + dx, y2 = y + dy;
        SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
        x1 = x2, y1 = y2;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 16);
    for (int i = 0; i < 640; i ++) {
        float height = sin(((double)i) / 10) * 10 + y;
        SDL_RenderDrawPointF(renderer, i, height);
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}