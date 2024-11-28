// C:\xampp\htdocs\Emulador\src\graphics\TextureManager.h

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <string>

class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    bool loadTexture(const std::string& filepath, SDL_Renderer* renderer);
    void freeTexture();
    SDL_Texture* getTexture() const;

private:
    SDL_Texture* texture;
};

#endif // TEXTUREMANAGER_H
