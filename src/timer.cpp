#include "timer.hpp"

// constructor initializes timer in stopped state
Timer::Timer() {
   isRunning = false;
   hasStarted = false;
}

// starts the timer
void Timer::start() {
   // if already running, restart from zero (TPQ #1)
   startTime = std::chrono::system_clock::now();
   isRunning = true;
   hasStarted = true;
}

// stops the timer
void Timer::stop() {
   // only stop if it was running
   if (isRunning) {
      stopTime = std::chrono::system_clock::now();
      isRunning = false;
   }
}

// returns elapsed time in seconds
long Timer::elapsed() {
   // if never started, return 0
   if (!hasStarted) {
      return 0;
   }

   // if currently running, calculate up to now
   if (isRunning) {
      auto currentTime = std::chrono::system_clock::now();

      // chrono measures in nanoseconds convert to whole seconds
      return std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
   }

   // otherwise calculate from start to stop
   // chrono measures in nanoseconds convert to whole seconds
   return std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime).count();
}
