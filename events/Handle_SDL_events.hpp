#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "../enums.hpp"

namespace DG2D
{
    extern std::vector<std::pair<SDL_EVENTS, std::vector<int>>> HandleEvents();
}