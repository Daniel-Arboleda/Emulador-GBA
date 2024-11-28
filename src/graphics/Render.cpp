// C:\xampp\htdocs\Emulador\src\graphics\Render.cpp

#include "Render.h"
#include <iostream>

Render::Render(int w, int h) : width(w), height(h), window(nullptr), renderer(nullptr), texture(nullptr) {}

Render::~Render() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    SDL_Quit();
}

bool Render::initialize() {
    if (!initSDL()) {
        std::cerr << "Error al inicializar SDL!" << std::endl;
        return false;
    }

    loadTextures();
    return true;
}

void Render::renderFrame() {
    // Aquí deberíamos tener un framebuffer donde se renderiza el contenido
    SDL_RenderClear(renderer);  // Limpiar pantalla

    // Renderizar textura
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    // Presentar el contenido
    SDL_RenderPresent(renderer);
}

void Render::clearScreen() {
    SDL_RenderClear(renderer);  // Limpiar el renderizado
}

void Render::presentScreen() {
    SDL_RenderPresent(renderer);  // Mostrar el contenido en la pantalla
}

bool Render::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Emulador", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Error al crear ventana: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Error al crear renderizador: " << SDL_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (!texture) {
        std::cerr << "Error al crear textura: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Render::loadTextures() {
    // Aquí cargaríamos las texturas necesarias utilizando la clase TextureManager
    textureManager.loadTexture("assets/screen.png", renderer);  // Ejemplo de carga de textura
}
