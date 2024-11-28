// C:\xampp\htdocs\Emulador\src\audio\SoundManager.cpp

#include "SoundManager.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>

SoundManager::SoundManager() : soundEffect(nullptr) {}

SoundManager::~SoundManager() {
    if (soundEffect) {
        Mix_FreeChunk(soundEffect);
    }
}

bool SoundManager::initialize() {
    soundEffect = nullptr;  // Asegurarse de que no haya efectos de sonido cargados inicialmente
    return true;
}

void SoundManager::playSound(const std::string& filePath) {
    if (loadSoundEffect(filePath)) {
        Mix_PlayChannel(-1, soundEffect, 0);  // Reproduce el sonido en cualquier canal disponible
    }
}

void SoundManager::stopAllSounds() {
    Mix_HaltChannel(-1);  // Detiene todos los canales de sonido
}

bool SoundManager::loadSoundEffect(const std::string& filePath) {
    soundEffect = Mix_LoadWAV(filePath.c_str());
    if (!soundEffect) {
        std::cerr << "Error al cargar efecto de sonido: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}
