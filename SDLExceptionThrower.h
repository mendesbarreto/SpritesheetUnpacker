//
// Created by Douglas Mendes on 2019-02-17.
//

#ifndef SPRITESHEETUNPACKER_SDLEXCEPTIONTHROWER_H
#define SPRITESHEETUNPACKER_SDLEXCEPTIONTHROWER_H

#include <string>
#include "SDL_image.h"
#include "SDL.h"

inline void throwSdlException(const std::string message) {
    std::string sdlErrorString = std::string(SDL_GetError());
    std::string errorString = message + sdlErrorString;\
    std::cout << errorString << std::endl;
    throw errorString;
}

inline void throwSdlImageException(const std::string message) {
    std::string sdlErrorString = std::string(IMG_GetError());
    std::string errorString = message + sdlErrorString;\
    std::cout << errorString << std::endl;
    throw errorString;
}

#endif //SPRITESHEETUNPACKER_SDLEXCEPTIONTHROWER_H
