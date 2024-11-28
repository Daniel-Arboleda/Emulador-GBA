// C:\xampp\htdocs\Emulador\src\audio\SoundManager.h

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SDL2/SDL_mixer.h>
#include <string>

class SoundManager {
public:
    SoundManager();
    ~SoundManager();

    bool initialize();
    void playSound(const std::string& filePath);
    void stopAllSounds();

private:
    Mix_Chunk* soundEffect;  // Sonido actual que está siendo reproducido

    bool loadSoundEffect(const std::string& filePath);  // Cargar un efecto de sonido
};

#endif // SOUNDMANAGER_H
