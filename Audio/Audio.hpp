#include <SDL2/SDL_mixer.h>
#include <string>

extern "C"
{
#include "../addons/beep/beep.h"
}

namespace DG2D
{
    namespace AUDIO
    {
        extern bool Init(int freq = 44100, Uint16 format = MIX_DEFAULT_FORMAT, int channels = 2, int chunksize = 2048, int numSFXChannels = 32);

        extern void Shutdown();

        extern Mix_Chunk* LoadSFX(std::string path);
    
        extern Mix_Music* LoadMusic(std::string path);

        extern int Beep(int frequency, int duration);
    
        extern void DestroySFX(Mix_Chunk* chunk);

        extern void SetSFXVolume(int volume);
    
        extern void SetSFXVolume(Mix_Chunk* chunk, int volume);
    
        extern void SetChannelVolume(int channel, int volume);
    
        extern void SetMusicVolume(int volume);
    
        extern void DestroyMusic(Mix_Music* music);
    
        extern void PlaySFX(Mix_Chunk* chunk);
    
        extern void PauseSFX();
    
        extern void StopSFX();
    
        extern void PlayMusic(Mix_Music* music, int loops);
    
        extern void PauseMusic();
    
        extern void ResumeMusic();
    
        extern void StopMusic();
    }
}