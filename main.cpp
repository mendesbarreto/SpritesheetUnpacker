#include <iostream>
#include "SDLProgram.h"

int main() {
    std::cout << "Starting SDL" << std::endl;
    auto sdlProgram = std::make_unique<SDLProgram>();
    std::cout << "RUNNING SDL" << std::endl;
    return sdlProgram->startSDLUpdate();
}