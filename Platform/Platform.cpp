#include "../enums.hpp"
#include <SDL2/SDL_platform.h>
#include "Platform.hpp"

namespace DG2D
{
    SDL_PLATFORMS GET_PLATFORM()
    {
        switch (*SDL_GetPlatform())
        {
            case *"Windows":
                return WIN_NT;
            case *"Mac OS X":
                return MACOS;
            case *"Linux":
                return UNIX_LINUX;
            case *"iOS":
                return IOS;
            case *"Android":
                return ANDROID;
            default:
                return UNKNOWN; //prob web
        }
    }
}