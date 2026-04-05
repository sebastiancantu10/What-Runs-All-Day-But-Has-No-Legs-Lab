#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "src/timer.hpp"

using namespace std;

int main() {
  Timer timer;

  // get the system start time
  auto systemStart = chrono::system_clock::now();

  // start timer
  timer.start();

  // wait for a few seconds
  this_thread::sleep_for(chrono::seconds(5));

  // stop timer
  timer.stop();

  // get the system end time
  auto systemEnd = chrono::system_clock::now();

  // calculate system elapsed time
  long systemElapsed = chrono::duration_cast<chrono::seconds>(systemEnd - systemStart).count();

  // get timer elapsed time
  long timerElapsed = timer.elapsed();

  // compare the times
  cout << "System time: " << systemElapsed << " seconds" << endl;
  cout << "Timer time: " << timerElapsed << " seconds" << endl;

  long difference = abs(systemElapsed - timerElapsed);

  if (difference <= 1) {
    cout << "Times are within acceptable range." << endl;
  }
  else {
    cout << "Times differ too much." << endl;
  }

  return 0;
}