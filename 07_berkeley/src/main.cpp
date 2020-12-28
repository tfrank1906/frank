#include <iostream>
#include <thread>
#include <string>
#include <chrono>

#include "clock.h"
#include "timeutils.h"

using namespace std;

class TimeSlave{
private:
  string Rechnername;
  chrono::time_point<chrono::system_clock> start_time;

public:
  TimeSlave(string Rechnername_, chrono::time_point<chrono::system_clock> start_time_){
    this->Rechnername = Rechnername_;
    this->start_time = start_time_;
  }
  void operator()(){
 
  }
}

};
int main(){
  thread clock{Clock("testclock", 5, 5, 5)};
  clock.join();
}
