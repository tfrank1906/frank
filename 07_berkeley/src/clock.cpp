#include <iostream>
#include <thread>
#include <chrono>

#include "clock.h"
#include "timeutils.h"

using namespace std;

void Clock::operator()(){
  while(true){
    cout << name << ": " << curr_time << endl;
    curr_time += 1s;
    this_thread::sleep_for(1s);
  }


}
