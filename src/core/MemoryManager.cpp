#include "MemoryManager.h"
#include <fstream>
#include <iostream>

MemoryManager::MemoryManager() {}

MemoryManager::~MemoryManager() {}

bool MemoryManager::loadROM(const std::string& romPath) {
    std::ifstream file(romPath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo ROM en: " << romPath << std::endl;
        return false;
    }

    memory = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
    file.close();

    std::cout << "ROM cargada exitosamente en la memoria (" << memory.size() << " bytes)." << std::endl;
    return true;
}

uint8_t* MemoryManager::getMemoryPointer() {
    return memory.data();
}

size_t MemoryManager::getMemorySize() const {
    return memory.size();
}
