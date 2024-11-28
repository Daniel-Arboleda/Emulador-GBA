#ifndef ROMMANAGER_H
#define ROMMANAGER_H

#include "ROMLoader.h"
#include <string>

class ROMManager {
public:
    ROMManager();                        // Constructor
    ~ROMManager();                       // Destructor

    bool initialize(const std::string& romPath); // Inicializa y carga una ROM
    const uint8_t* getROMPointer() const;        // Obtiene un puntero a los datos de la ROM
    size_t getROMSize() const;                   // Devuelve el tamaño de la ROM en bytes

private:
    ROMLoader romLoader;                 // Instancia de ROMLoader
    std::string loadedROMPath;           // Ruta de la ROM cargada
};

#endif // ROMMANAGER_H
