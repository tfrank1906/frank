#include <iostream>
#include <thread>
#include <string>
#include <chrono>


#include "clock.h"
#include "timeutils.h"


using namespace std;

class TimeSlave
{
private:
  string Rechnername;
  Clock c;

public:
  TimeSlave(string Rechnername_, int hours, int minutes, int seconds): c(Rechnername_, hours, minutes, seconds)
  {
  }
    void operator()()
    {
      c(); 
  }
};

class TimeMaster
{
private:
  string Rechnername;
  Clock c;

public:
  TimeMaster(string Rechnername_, int hours, int minutes, int seconds): c(Rechnername_, hours, minutes, seconds)
  {
  }
    void operator()()
    {
      c(); 
  }
};


int main()
{
  //thread clock{Clock("testclock", 5, 5, 5)};
  thread slave1{TimeSlave("slave1", 5, 5, 5)};
  thread slave2{TimeSlave("slave2", 6, 6, 6)};
  thread master{TimeMaster("master", 6, 6, 6)};
  
  //clock.join();
  slave1.join();
  slave2.join();
}
