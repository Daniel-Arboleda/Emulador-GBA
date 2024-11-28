// C:\xampp\htdocs\Emulador\src\network\NetworkUtils.h

#ifndef NETWORKUTILS_H
#define NETWORKUTILS_H

#include <string>
#include <vector>

int createSocket();
bool connectToServer(int socket, const std::string& serverIP, int port);
void closeSocket(int socket);

bool sendData(int socket, const std::vector<uint8_t>& data);
std::vector<uint8_t> receiveData(int socket);

#endif // NETWORKUTILS_H
