#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler {
public:
    InputHandler();              // Constructor
    ~InputHandler();             // Destructor

    void processInput();         // Procesa las entradas del usuario
    bool isExitRequested() const; // Indica si se solicitó salir del emulador

private:
    bool exitRequested;          // Estado de salida
};

#endif // INPUTHANDLER_H
