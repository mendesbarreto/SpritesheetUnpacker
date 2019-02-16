//
// Created by Douglas Mendes on 2019-02-16.
//

#ifndef SPRITESHEETUNPACKER_SDLPROGRAM_H
#define SPRITESHEETUNPACKER_SDLPROGRAM_H

#include "SDL.h"

class SDLProgram final{
public:
    SDL_Window* m_window;
    SDL_Surface* m_windowSurface;


public:
    SDLProgram();
    bool startSDLUpdate();

private:
    void initSDLVideo();
    void createWindow();
    void setupWindow();
};


#endif //SPRITESHEETUNPACKER_SDLPROGRAM_H
