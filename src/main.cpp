#include <iostream>
#include <filesystem>  // Para leer archivos del sistema de archivos
#include "core/Emulator.h"
#include "utils/ConfigManager.h"
#include "utils/Logger.h"
#include "graphics/Render.h"
#include "audio/AudioManager.h"
#include "network/NetworkManage.h"
#include "rom/ROMLoader.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    // Configurar el entorno: inicializar configuraciones y recursos
    ConfigManager config;
    Logger logger;
    AudioManager audioManager;
    Render renderer;
    NetworkManage networkManager;
    
    // Cargar configuración
    if (!config.load("config.ini")) {
        logger.logError("Error al cargar el archivo de configuración.");
        return -1;
    }

    // Inicializar el emulador
    Emulator emulator;
    if (!emulator.initialize()) {
        logger.logError("Error al inicializar el emulador.");
        return -1;
    }

    // Listar los archivos ROM disponibles en la carpeta
    std::string romsDir = "assets/roms/ROM";
    std::vector<std::string> romFiles;

    for (const auto& entry : fs::directory_iterator(romsDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".gba") {
            romFiles.push_back(entry.path().string());
        }
    }

    // Si no hay ROMs, mostrar un error y salir
    if (romFiles.empty()) {
        std::cout << "No se encontraron archivos ROM en la carpeta: " << romsDir << std::endl;
        return -1;
    }

    // Mostrar la lista de ROMs al usuario
    std::cout << "Seleccione un ROM para cargar:" << std::endl;
    for (size_t i = 0; i < romFiles.size(); ++i) {
        std::cout << i + 1 << ". " << romFiles[i] << std::endl;
    }

    int choice = 0;
    std::cout << "Ingrese el número del ROM: ";
    std::cin >> choice;

    if (choice < 1 || choice > romFiles.size()) {
        std::cout << "Selección no válida." << std::endl;
        return -1;
    }

    // Cargar el ROM seleccionado
    ROMLoader romLoader;
    if (!romLoader.loadROM(romFiles[choice - 1])) {
        std::cout << "No se pudo cargar el ROM seleccionado." << std::endl;
        return -1;
    }

    // Iniciar el ciclo de ejecución del emulador
    std::cout << "Iniciando emulador..." << std::endl;
    emulator.run();

    std::cout << "Emulador cerrado exitosamente." << std::endl;

    return 0;
}
