//
// Created by hyong on 12/27/20.
//

#include <iostream>
#include <SDL.h>
#include <string>
#include "res_path.h"

using namespace std;

int main (int argc, char** argv) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "SDL_Init Error" << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow(
            "ex1",
            100, 100, 640, 480,
            SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(
            win,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    for (int i = 0; i <= 255; i ++) {
        SDL_SetRenderDrawColor(ren, i, (255 + i) >> 1, 255 - i, 255);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
        SDL_Delay(10);
    }

    SDL_Delay(500);
    SDL_Quit();
    return 0;
}