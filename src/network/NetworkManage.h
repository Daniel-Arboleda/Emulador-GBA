
// C:\xampp\htdocs\Emulador\src\network\NetworkManage.h

#ifndef NETWORKMANAGE_H
#define NETWORKMANAGE_H

#include <string>
#include <vector>

class NetworkManage {
public:
    NetworkManage();
    ~NetworkManage();

    bool connectToServer(const std::string& serverIP, int port);  // Conectar al servidor
    void disconnect();  // Desconectar de la red
    bool sendData(const std::vector<uint8_t>& data);  // Enviar datos
    std::vector<uint8_t> receiveData();  // Recibir datos

private:
    int socket;  // El socket de la conexión
    bool isConnected;  // Estado de la conexión
};

#endif // NETWORKMANAGE_H
