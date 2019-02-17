//
// Created by Douglas Mendes on 2019-02-16.
//

#ifndef SPRITESHEETUNPACKER_SDLPROGRAM_H
#define SPRITESHEETUNPACKER_SDLPROGRAM_H

#include "SDL.h"
#include "SDL_image.h"

const int IMG_DEFAULT_EXTENSIONS_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG;

class SDLProgram final{
public:
    SDL_Window* m_window;
    SDL_Renderer* m_render;

public:
    SDLProgram();
    bool startSDLUpdate();

private:
    void initSDLVideo();
    void createWindow();
    void createRender();
    void setupBackgroundRender();
    void setupImageExtensionAllowed();
};


#endif //SPRITESHEETUNPACKER_SDLPROGRAM_H
