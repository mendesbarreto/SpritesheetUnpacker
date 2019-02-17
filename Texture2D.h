//
// Created by Douglas Mendes on 2019-02-17.
//

#ifndef SPRITESHEETUNPACKER_TEXTURE2D_H
#define SPRITESHEETUNPACKER_TEXTURE2D_H

#include <string>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Texture2D final {
private:
    std::string m_path;

public:
    SDL_Texture* m_texture;

private:
    Texture2D();
    Texture2D( std::string path );
    void loadTexture2D(SDL_Renderer* renderer);
    ~Texture2D();


public:
    static Texture2D* create(std::string path, SDL_Renderer* renderer);


};


#endif //SPRITESHEETUNPACKER_TEXTURE2D_H
