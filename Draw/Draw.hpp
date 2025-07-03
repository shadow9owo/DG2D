#include <SDL2/SDL_render.h>
#include "../Math/MathVars.hpp"
#include <cmath>

namespace DG2D
{
    extern void DrawLine(int x1,int y1,int x2,int y2);
    extern void DrawLineVecI(DG2D::Vector2I start,DG2D::Vector2I end);
    extern void DrawLineVec(DG2D::Vector2 start,DG2D::Vector2 end);
    extern void DrawRectVecI(DG2D::Vector2I Pos,DG2D::Vector2I size);
}