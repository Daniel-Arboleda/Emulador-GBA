// C:\xampp\htdocs\Emulador\src\network\NetworkManage.cpp

#include "NetworkManage.h"
#include "NetworkUtils.h"
#include <iostream>
#include <unistd.h>  // Para close() en Linux

NetworkManage::NetworkManage() : socket(-1), isConnected(false) {}

NetworkManage::~NetworkManage() {
    if (isConnected) {
        disconnect();
    }
}

bool NetworkManage::connectToServer(const std::string& serverIP, int port) {
    socket = createSocket();
    if (socket == -1) {
        std::cerr << "Error al crear socket!" << std::endl;
        return false;
    }

    if (!connectToServer(socket, serverIP, port)) {
        std::cerr << "Error al conectar al servidor!" << std::endl;
        return false;
    }

    isConnected = true;
    return true;
}

void NetworkManage::disconnect() {
    if (isConnected) {
        closeSocket(socket);
        isConnected = false;
    }
}

bool NetworkManage::sendData(const std::vector<uint8_t>& data) {
    if (!isConnected) {
        std::cerr << "No hay conexión establecida!" << std::endl;
        return false;
    }

    return sendData(socket, data);
}

std::vector<uint8_t> NetworkManage::receiveData() {
    if (!isConnected) {
        std::cerr << "No hay conexión establecida!" << std::endl;
        return {};
    }

    return receiveData(socket);
}
