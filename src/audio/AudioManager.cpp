// C:\xampp\htdocs\Emulador\src\audio\AudioManager.cpp

#include "AudioManager.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>

AudioManager::AudioManager() : volume(100) {}

AudioManager::~AudioManager() {
    Mix_CloseAudio();  // Cierra el sistema de audio de SDL
    Mix_Quit();
}

bool AudioManager::initialize() {
    if (!initAudioSubsystem()) {
        std::cerr << "Error al inicializar el sistema de audio!" << std::endl;
        return false;
    }

    soundManager.initialize();  // Inicializar el SoundManager
    return true;
}

void AudioManager::setVolume(int vol) {
    volume = vol;
    Mix_VolumeMusic(volume);  // Ajusta el volumen de la música
}

void AudioManager::playBackgroundMusic(const std::string& filePath) {
    if (Mix_PlayingMusic() == 0) {
        if (Mix_PlayMusic(Mix_LoadMUS(filePath.c_str()), -1) == -1) {
            std::cerr << "Error al reproducir música: " << Mix_GetError() << std::endl;
        }
    }
}

void AudioManager::stopBackgroundMusic() {
    Mix_HaltMusic();  // Detiene la música de fondo
}

bool AudioManager::initAudioSubsystem() {
    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        std::cerr << "Error al inicializar SDL_mixer: " << Mix_GetError() << std::endl;
        return false;
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        std::cerr << "Error al abrir el sistema de audio: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}
