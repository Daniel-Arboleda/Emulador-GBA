#ifndef ROMVALIDATOR_H
#define ROMVALIDATOR_H

#include <string>

class ROMValidator {
public:
    ROMValidator();                    // Constructor
    ~ROMValidator();                   // Destructor

    bool validateROM(const std::string& filePath); // Método para validar la ROM

private:
    // Pueden añadirse más métodos de validación si es necesario.
};

#endif // ROMVALIDATOR_H
