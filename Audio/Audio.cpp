#include <SDL2/SDL_mixer.h>
#include <string>
#include "Audio.hpp"

namespace DG2D
{
    namespace AUDIO
    {
        Mix_Chunk* LoadSFX(std::string path)
        {
            return Mix_LoadWAV(path.c_str());
        }
    
        Mix_Music* LoadMusic(std::string path)
        {
            return Mix_LoadMUS(path.c_str());
        }
    
        void DestroySFX(Mix_Chunk* chunk)
        {
            if (chunk) {
                Mix_FreeChunk(chunk);
            }
        }
    
        void DestroyMusic(Mix_Music* music)
        {
            if (music) {
                Mix_FreeMusic(music);
            }
        }
    
        void PlaySFX(Mix_Chunk* chunk)
        {
            if (chunk) Mix_PlayChannel(-1, chunk, 0);
        }
    
        void PauseSFX()
        {
            Mix_Pause(-1);
        }
    
        void StopSFX()
        {
            Mix_HaltChannel(-1);
        }
    
        void PlayMusic(Mix_Music* music, int loops)
        {
            if (music) Mix_PlayMusic(music, loops);
        }
    
        void PauseMusic()
        {
            Mix_PauseMusic();
        }
    
        void ResumeMusic()
        {
            Mix_ResumeMusic();
        }
    
        void StopMusic()
        {
            Mix_HaltMusic();
        }
    }
}