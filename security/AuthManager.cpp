#include "AuthManager.h"
#include <iostream>
#include <unordered_map>

// Simulación de una base de datos de usuarios y contraseñas (en un caso real, se usaría una base de datos segura)
std::unordered_map<std::string, std::string> users = {
    {"admin", "admin123"},
    {"user1", "password1"}
};

AuthManager::AuthManager() {
    // Inicializar la autenticación, si es necesario.
}

AuthManager::~AuthManager() {
    // Limpiar los recursos, si es necesario.
}

bool AuthManager::authenticate(const std::string& username, const std::string& password) {
    // Verificar si el usuario y la contraseña coinciden.
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

void AuthManager::login() {
    std::string username, password;
    std::cout << "Ingrese su nombre de usuario: ";
    std::cin >> username;
    std::cout << "Ingrese su contraseña: ";
    std::cin >> password;

    if (authenticate(username, password)) {
        std::cout << "Autenticación exitosa." << std::endl;
    } else {
        std::cout << "Error de autenticación. Usuario o contraseña incorrectos." << std::endl;
    }
}
