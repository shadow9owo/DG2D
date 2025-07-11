#include <string>
#include <SDL2/SDL_ttf.h>
#include "../Math/MathVars.hpp"
#include "../Draw/Draw.hpp"
#include <iostream>

namespace DG2D
{
    namespace Font
    {
        void DrawTTF(TTF_Font* font,std::string content,Vector4 dstrect,SDL_Color color)
        {
            if (!DG2D::DRAW::isrenderdeclared()) {std::cout << "ERR RENDERER NOT DECLARED" << std::endl;}
            SDL_Surface* surface = TTF_RenderText_Blended(font, content.c_str(), color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(DG2D::DRAW::globalrenderer, surface);
            SDL_FreeSurface(surface);
        
            SDL_Rect _DST = {(int)dstrect.x,(int)dstrect.y,(int)dstrect.z,(int)dstrect.w};
            SDL_RenderCopy(DG2D::DRAW::globalrenderer, texture, nullptr, &_DST);
        
            SDL_DestroyTexture(texture);
            return;
        }
    }
}