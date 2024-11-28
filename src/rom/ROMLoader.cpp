#include "ROMLoader.h"
#include <fstream>
#include <iostream>

ROMLoader::ROMLoader() {
    // Constructor: se puede inicializar romData si es necesario
}

ROMLoader::~ROMLoader() {
    // Destructor: no hay necesidad explícita de liberar memoria, ya que std::vector lo gestiona automáticamente
}

bool ROMLoader::loadROM(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary); // Abrir el archivo en modo binario
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo ROM en la ruta: " << filePath << std::endl;
        return false;
    }

    // Leer los datos del archivo en romData
    romData = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
    file.close();

    std::cout << "ROM cargada exitosamente desde: " << filePath << " (" << romData.size() << " bytes)" << std::endl;
    return true;
}

const std::vector<uint8_t>& ROMLoader::getROMData() const {
    return romData; // Retorna los datos de la ROM
}
