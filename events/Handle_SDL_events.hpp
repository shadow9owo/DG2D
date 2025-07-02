#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

enum SDL_EVENTS
{
    none = 0,
    quit,
    keydown,
    keyup,
    mousedown,
    mouseup,
    mousemove
};

namespace DG2D
{
    extern std::vector<std::pair<SDL_EVENTS, std::vector<int>>> HandleEvents();
}