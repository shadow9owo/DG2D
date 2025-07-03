#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace DG2D
{
    extern SDL_Texture Load_Texture(std::string path);
    extern void Unload_Texture(SDL_Texture *texture);
}