#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>
#include "CPU.h"
#include "MemoryManager.h"
#include "InputHandler.h"

class Emulator {
public:
    Emulator();                          // Constructor
    ~Emulator();                         // Destructor

    bool initialize(const std::string& romPath); // Inicializa el emulador con una ROM
    void run();                           // Ejecuta el bucle principal
    void stop();                          // Detiene el emulador

private:
    CPU cpu;                              // Instancia de la CPU
    MemoryManager memoryManager;          // Gestión de memoria
    InputHandler inputHandler;            // Manejo de entrada
    bool running;                         // Estado de ejecución del emulador
};

#endif // EMULATOR_H
