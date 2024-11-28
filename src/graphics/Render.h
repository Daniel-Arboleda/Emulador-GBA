// C:\xampp\htdocs\Emulador\src\graphics\Render.h

#ifndef RENDER_H
#define RENDER_H

#include "TextureManager.h"
#include <string>
#include <SDL2/SDL.h>  // Suponiendo que usaremos SDL2 para el renderizado

class Render {
public:
    Render(int width, int height);
    ~Render();

    bool initialize();
    void renderFrame();
    void clearScreen();
    void presentScreen();

private:
    int width;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    TextureManager textureManager;  // Para gestionar las texturas

    bool initSDL();  // Inicialización de SDL
    void loadTextures();  // Cargar las texturas iniciales si es necesario
};

#endif // RENDER_H
