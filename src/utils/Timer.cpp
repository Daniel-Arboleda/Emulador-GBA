#include "Timer.h"

Timer::Timer() {
    start();
}

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::elapsedMilliseconds() const {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(now - startTime).count();
}

double Timer::elapsedSeconds() const {
    return elapsedMilliseconds() / 1000.0;
}

void Timer::reset() {
    start();
}
