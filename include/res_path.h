//
// Created by hyong on 2020/11/30.
//

#ifndef SDLDEMO_RES_PATH_H
#define SDLDEMO_RES_PATH_H

#include <iostream>
#include <string>
#include <SDL.h>

std::string getResourcePath(const std::string &subDir = ""){
#ifdef _WIN32
    const char PATH_SEP = '\\';
#else
    const char PATH_SEP = '/';
#endif
    static std::string baseRes;
    if (baseRes.empty()){
        char *basePath = SDL_GetBasePath();
        if (basePath) {
            baseRes = basePath;
            SDL_free(basePath);
        } else {
            std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
            return "";
        }
        size_t pos = baseRes.rfind("bin");

        std::string tmp(baseRes);
        unsigned long long int idx = tmp.find("\\build");
        if (idx != std::string::npos) {
            tmp.erase(tmp.begin() + idx, tmp.begin() + idx + 6);
            baseRes = tmp;
        }

        baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
    }
    return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}
#endif //SDLDEMO_RES_PATH_H
