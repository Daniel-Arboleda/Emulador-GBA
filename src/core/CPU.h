#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <vector>

class CPU {
public:
    CPU();                         // Constructor
    ~CPU();                        // Destructor

    void reset();                  // Reinicia la CPU a su estado inicial
    void executeInstruction();     // Ejecuta una instrucción
    void loadMemory(uint8_t* memory, size_t size); // Carga la memoria en la CPU

private:
    uint32_t registers[16];        // Registros generales del GBA
    uint32_t programCounter;       // Contador de programa
    uint32_t stackPointer;         // Puntero de pila
    uint32_t statusRegister;       // Registro de estado
    uint8_t* memory;               // Memoria asociada
};

#endif // CPU_H
