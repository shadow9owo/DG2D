#include <SDL2/SDL.h>
#include <iostream>
#include "Handle_SDL_events.hpp"
#include <vector>

namespace DG2D
{
    std::vector<std::pair<SDL_EVENTS, std::vector<int>>> HandleEvents()
    {
        std::vector<std::pair<SDL_EVENTS, std::vector<int>>> events;
        SDL_Event e;
        int x, y;

        while (SDL_PollEvent(&e)) {
            switch (e.type)
            {
                case SDL_QUIT:
                    events.emplace_back(quit, std::vector<int>{});
                    break;

                case SDL_KEYDOWN:
                    events.emplace_back(keydown, std::vector<int>{e.key.keysym.sym});
                    break;

                case SDL_KEYUP:
                    events.emplace_back(keyup, std::vector<int>{e.key.keysym.sym});
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&x, &y);
                    events.emplace_back(mousedown, std::vector<int>{e.button.button, x, y});
                    break;

                case SDL_MOUSEBUTTONUP:
                    SDL_GetMouseState(&x, &y);
                    events.emplace_back(mouseup, std::vector<int>{e.button.button, x, y});
                    break;

                case SDL_MOUSEMOTION:
                    events.emplace_back(mousemove, std::vector<int>{e.motion.x, e.motion.y});
                    break;

                default:
                    events.emplace_back(none, std::vector<int>{});
                    break;
            }
        }
        return events;
    }
}
