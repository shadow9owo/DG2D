#include <SDL2/SDL.h>
#include <iostream>
#include "Handle_SDL_events.hpp"
#include <vector>

namespace DG2D
{
    std::vector<std::pair<SDL_EVENTS, int>> HandleEvents()
    {
        std::vector<std::pair<SDL_EVENTS, int>> events;
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            switch (e.type)
            {
                case SDL_QUIT:
                    events.emplace_back(quit, none);
                    break;

                case SDL_KEYDOWN:
                    events.emplace_back(keydown, e.key.keysym.sym);
                    break;

                case SDL_KEYUP:
                    events.emplace_back(keyup, e.key.keysym.sym); 
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    events.emplace_back(mousedown, e.button.button);
                    break;

                case SDL_MOUSEBUTTONUP:
                    events.emplace_back(mouseup, e.button.button);
                    break;

                default:
                    events.emplace_back(none, none);
                    break;
            }
        }
        return events;
    }
}
