#include <SDL2/SDL_mixer.h>
#include <string>
#include "Audio.hpp"

extern "C"
{
#include "../addons/beep/beep.h"
}

namespace DG2D
{
    namespace AUDIO
    {
        bool Init(int freq = 44100, Uint16 format = MIX_DEFAULT_FORMAT, int channels = 2, int chunksize = 2048, int numSFXChannels = 32)
        {
            if (Mix_OpenAudio(freq, format, channels, chunksize) == -1) {
                return false;
            }
            Mix_AllocateChannels(numSFXChannels);
            return true;
        }
        void Shutdown()
        {
            Mix_CloseAudio();
        }

        Mix_Chunk* LoadSFX(std::string path)
        {
            return Mix_LoadWAV(path.c_str());
        }
    
        Mix_Music* LoadMusic(std::string path)
        {
            return Mix_LoadMUS(path.c_str());
        }

        int Beep(int frequency, int duration)
        {
            return beep(frequency,duration);
        }
    
        void DestroySFX(Mix_Chunk* chunk)
        {
            if (chunk) {
                Mix_FreeChunk(chunk);
            }
        }

        void SetSFXVolume(int volume)
        {
            Mix_Volume(-1, volume);
        }
    
        void SetSFXVolume(Mix_Chunk* chunk, int volume)
        {
            if (chunk)
                Mix_VolumeChunk(chunk, volume);
        }
    
        void SetChannelVolume(int channel, int volume)
        {
            Mix_Volume(channel, volume);
        }
    
        void SetMusicVolume(int volume)
        {
            Mix_VolumeMusic(volume);
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