// C:\xampp\htdocs\Emulador\src\graphics\TextureManager.cpp

#include "TextureManager.h"
#include <SDL2/SDL_image.h>
#include <iostream>

TextureManager::TextureManager() : texture(nullptr) {}

TextureManager::~TextureManager() {
    freeTexture();
}

bool TextureManager::loadTexture(const std::string& filepath, SDL_Renderer* renderer) {
    freeTexture();  // Liberar cualquier textura cargada previamente

    texture = IMG_LoadTexture(renderer, filepath.c_str());
    if (!texture) {
        std::cerr << "Error al cargar la textura: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void TextureManager::freeTexture() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

SDL_Texture* TextureManager::getTexture() const {
    return texture;
}
