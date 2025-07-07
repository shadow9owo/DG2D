#include "FPSutils.hpp"
#include <SDL2/SDL.h>

namespace DG2D
{
    namespace Math
    {
        float FPSTarget(int fps)
        {
            return 1 / fps;
        }

        long last = 0;
        float deltaTime = 0.0;

        float GetDeltaTime()
        {
            long now = SDL_GetTicks();

            if (now > last) {
            	deltaTime = ((float)(now - last)) / 1000;
            	last = now;
            }
            return deltaTime;
        }
    }
}