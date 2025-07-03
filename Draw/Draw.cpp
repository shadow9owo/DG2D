#include <SDL2/SDL_render.h>
#include "../Math/MathVars.hpp"
#include "Draw.hpp"
#include <SDL2/SDL.h>
#include <iostream>

namespace DG2D
{
    SDL_Renderer *globalrenderer = nullptr;

    bool isrenderdeclared()
    {
        if (globalrenderer == nullptr)
        {
            return false;
        }else {
            return true;
        }
    }

    void DrawLine(int x1,int y1,int x2,int y2,SDL_Color color)
    {
        if (!isrenderdeclared()) {std::cout << "ERR RENDERER NOT DECLARED" << std::endl;}
        SDL_SetRenderDrawColor(globalrenderer,color.r,color.g,color.b,color.a);
        SDL_RenderDrawLine(globalrenderer,x1,y1,x2,y2);
        return;
    }
    void DrawLineVecI(DG2D::Vector2I start,DG2D::Vector2I end,SDL_Color color)
    {
        if (!isrenderdeclared()) {std::cout << "ERR RENDERER NOT DECLARED" << std::endl;}
        SDL_SetRenderDrawColor(globalrenderer,color.r,color.g,color.b,color.a);
        SDL_RenderDrawLine(globalrenderer,start.x,start.y,end.x,end.y);
        return;
    }
    void DrawLineVec(DG2D::Vector2 start,DG2D::Vector2 end,SDL_Color color)
    {
        if (!isrenderdeclared()) {std::cout << "ERR RENDERER NOT DECLARED" << std::endl;}
        SDL_SetRenderDrawColor(globalrenderer,color.r,color.g,color.b,color.a);
        SDL_RenderDrawLine(globalrenderer,start.x,start.y,end.x,end.y);
        return;
    }
    void DrawRectVecI(DG2D::Vector2I Pos,DG2D::Vector2I size,SDL_Color color,bool fill)
    {
        if (!isrenderdeclared()) {std::cout << "ERR RENDERER NOT DECLARED" << std::endl;}
        SDL_Rect rect;
        rect.x = Pos.x;
        rect.y = Pos.y;
        rect.w = size.x;
        rect.h = size.y;

        SDL_SetRenderDrawColor(globalrenderer,color.r,color.b,color.g,color.a);

        if (fill)
        {
            SDL_RenderFillRect(globalrenderer, &rect);
        }
        else 
        {
            SDL_RenderDrawRect(globalrenderer,&rect);
        }
        return;
    }
    void Define_Renderer(SDL_Renderer *renderer)
    {
        globalrenderer = renderer;
    }
}