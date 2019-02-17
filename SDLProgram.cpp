//
// Created by Douglas Mendes on 2019-02-16.
//

#include "SDLProgram.h"
#include <iostream>
#include <string>
#include <SDL_image.h>
#include "SDLExceptionThrower.h"
#include "Texture2D.h"

constexpr char SDL_WINDOW_TITLE_NAME[21] = {"Spritesheet Unpacker"};

bool SDLProgram::startSDLUpdate() {

    bool canQuit = false;
    SDL_Event event;

    auto texture2D = Texture2D::create("resource/megaman_poses.png", m_render);

    while (!canQuit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                canQuit = true;
            }

            //Clear screen
            SDL_RenderClear( m_render );

            //Render texture to screen
            SDL_RenderCopy( m_render, texture2D->m_texture, NULL, NULL );

            //Update screen
            SDL_RenderPresent( m_render );
        }
    }

    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);

    m_render = nullptr;
    m_window = nullptr;
    texture2D = nullptr;

    IMG_Quit();
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

void SDLProgram::createRender() {
    m_render = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_render == NULL) { throwSdlException("Could not create the render"); }
}

void SDLProgram::setupBackgroundRender() {
    SDL_SetRenderDrawColor( m_render, 0, 0xFF, 0xFF, 0xFF );
}

void SDLProgram::setupImageExtensionAllowed() {
    if (!( IMG_Init(IMG_DEFAULT_EXTENSIONS_FLAGS) & IMG_DEFAULT_EXTENSIONS_FLAGS ) ) {
        throwSdlImageException("Could initialize img default extensions");
    }
}

SDLProgram::SDLProgram(){
    this->initSDLVideo();
    this->createWindow();
    this->createRender();
    this->setupBackgroundRender();
    this->setupImageExtensionAllowed();
}
