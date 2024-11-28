#include "CPU.h"
#include <iostream>

CPU::CPU() : programCounter(0), stackPointer(0), statusRegister(0), memory(nullptr) {
    reset();
}

CPU::~CPU() {}

void CPU::reset() {
    programCounter = 0;
    stackPointer = 0;
    statusRegister = 0;

    for (auto& reg : registers) {
        reg = 0;
    }

    std::cout << "CPU reiniciada." << std::endl;
}

void CPU::executeInstruction() {
    if (!memory) {
        std::cerr << "Error: Memoria no cargada en la CPU." << std::endl;
        return;
    }

    // Aquí iría la lógica para decodificar y ejecutar instrucciones
    std::cout << "Ejecutando instrucción en dirección: " << programCounter << std::endl;

    programCounter += 4; // Incremento del PC como ejemplo
}

void CPU::loadMemory(uint8_t* mem, size_t size) {
    memory = mem;
    std::cout << "Memoria cargada en la CPU (tamaño: " << size << " bytes)." << std::endl;
}
