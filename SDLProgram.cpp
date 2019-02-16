//
// Created by Douglas Mendes on 2019-02-16.
//

#include "SDLProgram.h"
#include <iostream>
#include <string>

constexpr char SDL_WINDOW_TITLE_NAME[21] = {"Spritesheet Unpacker"};

void throwSdlException(const std::string message) {
    std::string sdlErrorString = std::string(SDL_GetError());
    std::string errorString = message + sdlErrorString;
    throw errorString;
}

bool SDLProgram::startSDLUpdate() {

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_FreeSurface(m_windowSurface);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return false;
}

void SDLProgram::initSDLVideo() {
    if( SDL_Init(SDL_INIT_VIDEO) ) {
        throwSdlException("SDL could not initialize! SDL_Error: \n");
    }
}

void SDLProgram::createWindow() {
    m_window = SDL_CreateWindow(
            SDL_WINDOW_TITLE_NAME,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN
    );

    if( m_window == NULL ) {
        throwSdlException("SDL could not initialize the window! SDL_Error: \n");
    }
}


void SDLProgram::setupWindow() {
    m_windowSurface = SDL_GetWindowSurface(m_window);
    SDL_FillRect( m_windowSurface, NULL, SDL_MapRGB( m_windowSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(m_window);
}

SDLProgram::SDLProgram(){
    this->initSDLVideo();
    this->createWindow();
    this->setupWindow();
}
