#include "utils/utils.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "enums.hpp"

#pragma once

namespace DG2D
{
    extern bool isdebugbuild;
    namespace GLOBALS
    {
        struct Event {
            SDL_EVENTS type;
            std::vector<int> data;

            Event(SDL_EVENTS t, std::vector<int> d)
                : type(t), data(std::move(d)) {} // quick ugly hack stolen from stackoverflow
        };
    }
}