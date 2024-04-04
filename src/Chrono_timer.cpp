#include "Chrono_timer.h"

Chrono::Chrono() {}

Chrono::~Chrono() {}

void Chrono::start() {
    startTime = std::chrono::steady_clock::now();
}

void Chrono::stop() {
    endTime = std::chrono::steady_clock::now();
}

double Chrono::elapsedMilliseconds() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}
