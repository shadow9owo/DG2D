#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Draw/Draw.hpp"
#include <iostream>
#include <string>

namespace DG2D
{
    SDL_Texture* Load_Texture(std::string path)
    {
        if (!DG2D::isrenderdeclared()) {std::cout << "ERR RENDERER NOT DECLARED" << std::endl;}
        return IMG_LoadTexture(DG2D::globalrenderer,path.c_str());
    }
    void Unload_Texture(SDL_Texture *texture)
    {
        SDL_DestroyTexture(texture);
        return;
    }
}