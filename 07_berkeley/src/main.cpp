#include <iostream>
#include <thread>
#include <chrono>

#include "clock.h"
#include "timeutils.h"


using namespace std;

int main(){
  thread clock{Clock("testclock" , 5, 5, 5)};
  clock.join();

}


