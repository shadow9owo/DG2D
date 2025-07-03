#include <SDL2/SDL_render.h>
#include "../Math/MathVars.hpp"
#include <SDL2/SDL.h>
#include <cmath>

namespace DG2D
{
    extern SDL_Renderer *globalrenderer;
    extern bool isrenderdeclared();
    extern void DrawLine(int x1,int y1,int x2,int y2,SDL_Color color);
    extern void DrawLineVecI(DG2D::Vector2I start,DG2D::Vector2I end,SDL_Color color);
    extern void DrawLineVec(DG2D::Vector2 start,DG2D::Vector2 end,SDL_Color color);
    extern void DrawRectVecI(DG2D::Vector2I Pos,DG2D::Vector2I size,SDL_Color color,bool fill);
    extern void Define_Renderer(SDL_Renderer *renderer);
    extern void DrawTextureVecI(SDL_Texture *texture,DG2D::Vector2I Pos,DG2D::Vector2I size);
    extern void DrawTextureVec(SDL_Texture *texture,DG2D::Vector2I Pos,DG2D::Vector2I size);
}