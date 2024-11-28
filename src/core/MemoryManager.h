#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <cstddef>
#include <string>
#include <vector>

class MemoryManager {
public:
    MemoryManager();                        // Constructor
    ~MemoryManager();                       // Destructor

    bool loadROM(const std::string& romPath); // Carga una ROM en la memoria
    uint8_t* getMemoryPointer();             // Obtiene un puntero a la memoria cargada
    size_t getMemorySize() const;            // Obtiene el tamaño de la memoria

private:
    std::vector<uint8_t> memory;            // Contenedor de la memoria
};

#endif // MEMORYMANAGER_H
