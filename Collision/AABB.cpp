#include "../Math/MathVars.hpp"

namespace DG2D
{
    bool IsRectColliding(DG2D::Vector4 a, DG2D::Vector4 b) //simple aabb
    {
        return (a.x < b.x + b.z) &&
               (a.x + a.z > b.x) &&
               (a.y < b.y + b.w) &&
               (a.y + a.w > b.y);  
    }
}