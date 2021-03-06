#include <iostream>
#include <thread>
#include <chrono>
#include "utils.h"
#include "clock.h"
#include "timeutils.h"

mutex mtx;
using namespace std;

void Clock::operator()(){
  while(true){
    mtx.lock();
    cout << name << ": " << curr_time << endl;
    mtx.unlock();
    curr_time += 1s;
    this_thread::sleep_for(1s);
  }


}

void Clock::set_time(int hours, int minutes, int seconds){
  curr_time = chrono::system_clock::now();
  curr_time = timeutils::set_time(curr_time, hours, minutes, seconds);
}

tuple<int, int, int> Clock::get_time(){
  return timeutils::get_time(this->curr_time);
}