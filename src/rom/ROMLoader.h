#ifndef ROMLOADER_H
#define ROMLOADER_H

#include <string>
#include <vector>

class ROMLoader {
public:
    ROMLoader();                      // Constructor
    ~ROMLoader();                     // Destructor

    bool loadROM(const std::string& filePath);  // Carga una ROM desde la ruta proporcionada
    const std::vector<uint8_t>& getROMData() const; // Devuelve los datos de la ROM en formato binario

private:
    std::vector<uint8_t> romData;     // Contenedor para almacenar los datos de la ROM
};

#endif // ROMLOADER_H
