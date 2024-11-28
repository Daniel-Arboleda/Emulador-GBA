// C:\xampp\htdocs\Emulador\src\network\NetworkUtils.cpp

#include "NetworkUtils.h"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int createSocket() {
    return socket(AF_INET, SOCK_STREAM, 0);  // Crea un socket TCP
}

bool connectToServer(int socket, const std::string& serverIP, int port) {
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());

    return connect(socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == 0;
}

void closeSocket(int socket) {
    close(socket);
}

bool sendData(int socket, const std::vector<uint8_t>& data) {
    return send(socket, data.data(), data.size(), 0) > 0;
}

std::vector<uint8_t> receiveData(int socket) {
    std::vector<uint8_t> buffer(1024);
    ssize_t bytesReceived = recv(socket, buffer.data(), buffer.size(), 0);
    buffer.resize(bytesReceived);
    return buffer;
}
