// C:\xampp\htdocs\Emulador\src\audio\AudioManager.h

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <string>
#include "SoundManager.h"

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    bool initialize();
    void setVolume(int volume);  // Ajustar el volumen global
    void playBackgroundMusic(const std::string& filePath);
    void stopBackgroundMusic();

private:
    SoundManager soundManager;  // Para manejar efectos de sonido y música
    int volume;  // Volumen global

    bool initAudioSubsystem();  // Inicializar el sistema de audio
};

#endif // AUDIOMANAGER_H
