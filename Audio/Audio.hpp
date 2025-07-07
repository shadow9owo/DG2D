#include <SDL2/SDL_mixer.h>
#include <string>

namespace DG2D
{
    namespace AUDIO
    {
        extern Mix_Chunk* LoadSFX(std::string path);
        extern Mix_Music* LoadMusic(std::string path);

        extern void DestroySFX(Mix_Chunk* chunk);
        extern void DestroyMusic(Mix_Music* music);

        extern void PlaySFX(Mix_Chunk* chunk);
        extern void PauseSFX();
        extern void StopSFX();

        extern void PlayMusic(Mix_Music* music, int loops = -1);
        extern void PauseMusic();
        extern void ResumeMusic();
        extern void StopMusic();
    }
}