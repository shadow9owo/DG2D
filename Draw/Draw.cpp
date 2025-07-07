#include <SDL2/SDL.h>
#include "../Math/MathVars.hpp"
#include "Draw.hpp"
#include <iostream>

namespace DG2D
{
    namespace DRAW
    {
        SDL_Renderer *globalrenderer = nullptr;
        SDL_Texture *globalbuffer = nullptr;
        bool isrenderdeclared()
        {
            return (globalrenderer != nullptr && globalbuffer != nullptr);
        }
        void Define_Renderer(SDL_Renderer *renderer)
        {
            globalrenderer = renderer;
        }
        SDL_Texture* CreateRenderTexture(Vector2I windowsize, SDL_Renderer *RendererReference) //returns render texture
        {
            SDL_Texture* b = SDL_CreateTexture(
                RendererReference,
                SDL_PIXELFORMAT_RGBA8888,
                SDL_TEXTUREACCESS_TARGET,
                windowsize.x,
                windowsize.y
            );
            return b;
        }
        void GlobalDefineTexture(SDL_Texture *texture)
        {
            globalbuffer = texture;
        }

        void StartDraw(SDL_Color clearcolor)
        {
            if (!isrenderdeclared()) 
            {
                std::cout << "ERR: RENDERER OR BUFFER NOT DECLARED\n"; 
                return;
            }
            SDL_SetRenderTarget(globalrenderer, globalbuffer);
            SDL_SetRenderDrawColor(globalrenderer, clearcolor.r,clearcolor.g,clearcolor.b,clearcolor.a); 
            SDL_RenderClear(globalrenderer);
        }
        
        void EndDraw()
        {
            if (!isrenderdeclared()) 
            {
                std::cout << "ERR: RENDERER OR BUFFER NOT DECLARED\n"; 
                return;
            }
            SDL_SetRenderTarget(globalrenderer, nullptr);
            SDL_RenderCopy(globalrenderer, globalbuffer, nullptr, nullptr);
        }

        void DrawLine(int x1, int y1, int x2, int y2, SDL_Color color)
        {
            if (!isrenderdeclared()) { std::cout << "ERR: RENDERER OR BUFFER NOT DECLARED\n"; return; }
            SDL_SetRenderTarget(globalrenderer, globalbuffer);
            SDL_SetRenderDrawColor(globalrenderer, color.r, color.g, color.b, color.a);
            SDL_RenderDrawLine(globalrenderer, x1, y1, x2, y2);
            SDL_SetRenderTarget(globalrenderer, nullptr);
        }
        void DrawLineVecI(DG2D::Vector2I start, DG2D::Vector2I end, SDL_Color color)
        {
            DrawLine(start.x, start.y, end.x, end.y, color);
        }
        void DrawLineVec(DG2D::Vector2 start, DG2D::Vector2 end, SDL_Color color)
        {
            DrawLine((int)(start.x),(int)(start.y),(int)(end.x),(int)(end.y),color);
        }
        void DrawRectVecI(DG2D::Vector2I Pos, DG2D::Vector2I size, SDL_Color color, bool fill)
        {
            if (!isrenderdeclared()) { std::cout << "ERR: RENDERER OR BUFFER NOT DECLARED\n"; return; }
            SDL_SetRenderTarget(globalrenderer, globalbuffer);
            SDL_Rect rect = { Pos.x, Pos.y, size.x, size.y };
            SDL_SetRenderDrawColor(globalrenderer, color.r, color.g, color.b, color.a);
            if (fill)
            {
                SDL_RenderFillRect(globalrenderer, &rect);
            }
            else
            {
                SDL_RenderDrawRect(globalrenderer, &rect);
            }
            SDL_SetRenderTarget(globalrenderer, nullptr);
        }
        void DrawTextureVecI(SDL_Texture *texture, DG2D::Vector2I Pos, DG2D::Vector2I size)
        {
            if (!isrenderdeclared()) { std::cout << "ERR: RENDERER OR BUFFER NOT DECLARED\n"; return; }
            SDL_SetRenderTarget(globalrenderer, globalbuffer);
            SDL_Rect rect = { Pos.x, Pos.y, size.x, size.y };
            SDL_RenderCopy(globalrenderer, texture, nullptr, &rect);
            SDL_SetRenderTarget(globalrenderer, nullptr);
        }
        void DrawTextureVec(SDL_Texture *texture, DG2D::Vector2I Pos, DG2D::Vector2I size)
        {
            DrawTextureVecI(texture, Pos, size);
        }
    }
}
