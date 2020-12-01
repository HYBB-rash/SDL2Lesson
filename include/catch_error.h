//
// Created by hyong on 2020/12/1.
//

#ifndef SDL2DEMO_CATCH_ERROR_H
#define SDL2DEMO_CATCH_ERROR_H

#include <iostream>
#include <SDL.h>

/**
 * 将一些SDL错误记录到我们的信息流里面去
 * @param os 输入流
 * @param msg 错误信息
 */
void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}
#endif //SDL2DEMO_CATCH_ERROR_H
