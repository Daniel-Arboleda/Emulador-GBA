#include "ConfigManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

ConfigManager::ConfigManager() {}

ConfigManager::~ConfigManager() {}

bool ConfigManager::loadConfig(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de configuración: " << filePath << std::endl;
        return false;
    }

    configData.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            configData[key] = value;
        }
    }
    file.close();
    return true;
}

bool ConfigManager::saveConfig(const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo guardar el archivo de configuración: " << filePath << std::endl;
        return false;
    }

    for (const auto& [key, value] : configData) {
        file << key << "=" << value << "\n";
    }
    file.close();
    return true;
}

std::string ConfigManager::getValue(const std::string& key) const {
    auto it = configData.find(key);
    return (it != configData.end()) ? it->second : "";
}

void ConfigManager::setValue(const std::string& key, const std::string& value) {
    configData[key] = value;
}
