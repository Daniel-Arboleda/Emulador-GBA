
#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer();                               // Constructor
    void start();                          // Inicia el temporizador
    double elapsedMilliseconds() const;   // Tiempo transcurrido en ms
    double elapsedSeconds() const;        // Tiempo transcurrido en segundos
    void reset();                          // Reinicia el temporizador

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif // TIMER_H
