#include "Emulator.h"
#include <iostream>

Emulator::Emulator() : running(false) {}

Emulator::~Emulator() {}

bool Emulator::initialize(const std::string& romPath) {
    if (!memoryManager.loadROM(romPath)) {
        std::cerr << "Error: No se pudo cargar la ROM." << std::endl;
        return false;
    }

    cpu.loadMemory(memoryManager.getMemoryPointer(), memoryManager.getMemorySize());
    running = true;
    std::cout << "Emulador inicializado con la ROM: " << romPath << std::endl;
    return true;
}

void Emulator::run() {
    while (running) {
        inputHandler.processInput();

        cpu.executeInstruction();

        if (inputHandler.isExitRequested()) {
            stop();
        }
    }
}

void Emulator::stop() {
    running = false;
    std::cout << "Emulador detenido." << std::endl;
}
