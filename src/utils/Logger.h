#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    enum class LogLevel { INFO, WARNING, ERROR };

    static void initialize(const std::string& logFilePath); // Inicializa el logger con un archivo
    static void log(LogLevel level, const std::string& message); // Escribe un mensaje de log
    static void shutdown();                                    // Cierra el archivo de log

private:
    Logger() = delete; // Constructor eliminado, solo métodos estáticos
    static std::string logLevelToString(LogLevel level); // Convierte niveles a string
    static std::ofstream logFile;                       // Archivo de log
};

#endif // LOGGER_H
