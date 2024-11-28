#include "ROMValidator.h"
#include <iostream>
#include <fstream>

ROMValidator::ROMValidator() {
    // Inicialización si es necesario
}

ROMValidator::~ROMValidator() {
    // Limpiar los recursos si es necesario
}

bool ROMValidator::validateROM(const std::string& filePath) {
    // Verificar que el archivo existe
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo ROM en la ruta: " << filePath << std::endl;
        return false;
    }

    // Realizar una validación simple: verificar que la extensión es .gba
    if (filePath.substr(filePath.find_last_of(".") + 1) != "gba") {
        std::cerr << "Error: El archivo no tiene la extensión .gba" << std::endl;
        return false;
    }

    // Verificación simple de la firma del archivo ROM (en este caso, asumimos que los primeros 4 bytes deben ser "GBA\0")
    char signature[4];
    file.read(signature, 4);
    if (file.gcount() < 4 || signature[0] != 'G' || signature[1] != 'B' || signature[2] != 'A') {
        std::cerr << "Error: El archivo ROM no es válido." << std::endl;
        return false;
    }

    std::cout << "ROM válida." << std::endl;
    return true;
}
