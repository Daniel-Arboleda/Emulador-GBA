#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

std::ofstream Logger::logFile;

void Logger::initialize(const std::string& logFilePath) {
    logFile.open(logFilePath, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de log: " << logFilePath << std::endl;
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string timestamp;
    auto now = std::time(nullptr);
    timestamp.resize(20);
    std::strftime(timestamp.data(), timestamp.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::string logMessage = "[" + timestamp + "] [" + logLevelToString(level) + "] " + message;

    if (logFile.is_open()) {
        logFile << logMessage << std::endl;
    }

    std::cout << logMessage << std::endl; // También se muestra en la consola
}

void Logger::shutdown() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

std::string Logger::logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        default:                return "UNKNOWN";
    }
}
