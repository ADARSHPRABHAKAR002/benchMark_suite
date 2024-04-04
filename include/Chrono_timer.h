#ifndef CHRONO_H
#define CHRONO_H

#include <chrono>

class Chrono {
public:
    Chrono();
    ~Chrono();

    void start();
    void stop();
    double elapsedMilliseconds() const;

private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
};

#endif // CHRONO_H
