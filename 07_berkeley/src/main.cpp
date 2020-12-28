#include <iostream>
#include <thread>
#include <chrono>

#include "clock.h"
#include "timeutils.h"


using namespace std;

int main(){
  thread clock{Clock("testclock")};
  clock.join();

}


