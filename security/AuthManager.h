#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <string>

class AuthManager {
public:
    AuthManager();                  // Constructor
    ~AuthManager();                 // Destructor

    void login();                   // Método para iniciar sesión
    bool authenticate(const std::string& username, const std::string& password); // Autenticación

private:
    // En un escenario real, podrían almacenarse más detalles de autenticación.
};

#endif // AUTHMANAGER_H
