#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <string>
#include <unordered_map>

class ConfigManager {
public:
    ConfigManager();                              // Constructor
    ~ConfigManager();                             // Destructor

    bool loadConfig(const std::string& filePath); // Carga la configuración desde un archivo
    bool saveConfig(const std::string& filePath); // Guarda la configuración en un archivo
    std::string getValue(const std::string& key) const; // Obtiene un valor por clave
    void setValue(const std::string& key, const std::string& value); // Establece un valor por clave

private:
    std::unordered_map<std::string, std::string> configData; // Almacena las configuraciones clave-valor
};

#endif // CONFIGMANAGER_H
