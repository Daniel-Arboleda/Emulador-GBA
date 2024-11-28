#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler() : exitRequested(false) {}

InputHandler::~InputHandler() {}

void InputHandler::processInput() {
    // Aquí se manejaría la entrada del usuario (por ejemplo, teclas)
    std::cout << "Procesando entrada del usuario..." << std::endl;

    // Simulación: establecer exitRequested si una tecla específica es presionada
    // exitRequested = true; // Ejemplo
}

bool InputHandler::isExitRequested() const {
    return exitRequested;
}
