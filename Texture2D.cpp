//
// Created by Douglas Mendes on 2019-02-17.
//
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDLExceptionThrower.h"
#include "Texture2D.h"

Texture2D::Texture2D(std::string path) {
    m_path = path;
}

void Texture2D::loadTexture2D(SDL_Renderer *renderer) {
    m_texture = IMG_LoadTexture(renderer, m_path.c_str());

    if (m_texture == NULL) {
        throwSdlImageException("Could not load texture \n");
    }
}


Texture2D *Texture2D::create(std::string path, SDL_Renderer *renderer) {
    auto texture2D = new Texture2D(path);
    texture2D->loadTexture2D(renderer);
    return texture2D;
}

Texture2D::~Texture2D() {
    SDL_DestroyTexture(m_texture);
    m_texture = NULL;
    std::cout << "The object Texture2D was destroyed" << std::endl;
}
