#include "ROMManager.h"
#include <iostream>

ROMManager::ROMManager() : loadedROMPath("") {
    // Constructor: puede inicializar cualquier variable si es necesario
}

ROMManager::~ROMManager() {
    // Destructor: no es necesario liberar memoria manualmente
}

bool ROMManager::initialize(const std::string& romPath) {
    if (!romLoader.loadROM(romPath)) {
        std::cerr << "Error: No se pudo inicializar la ROM desde: " << romPath << std::endl;
        return false;
    }

    loadedROMPath = romPath;
    std::cout << "ROMManager: ROM cargada desde: " << loadedROMPath << std::endl;
    return true;
}

const uint8_t* ROMManager::getROMPointer() const {
    return romLoader.getROMData().data(); // Devuelve un puntero al inicio de los datos de la ROM
}

size_t ROMManager::getROMSize() const {
    return romLoader.getROMData().size(); // Devuelve el tamaño de los datos de la ROM
}
