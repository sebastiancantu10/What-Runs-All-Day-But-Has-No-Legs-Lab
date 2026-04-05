#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer {
private:
    // start and stop times
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> stopTime;

    // status
    bool isRunning;
    bool hasStarted;

public:
    // constructor
    Timer();

    // methods
    void start();
    void stop();

    // returns time in whole seconds
    long elapsed();
};

#endif