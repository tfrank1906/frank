#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <initializer_list>
#include "CLI11.hpp"

#include "philosopher.h"
#include "semaphor.h"
using namespace std;

//Bsp wurde mit Herrn Groß ausgearbeitet :)
int main(int argc, const char* argv[])
{
  Semaphore s{4};
  Semaphore *pointer = &s;
  //pointer = nullptr;

  CLI::App app("dining");
  bool live{false};
  bool no_deadlock{};
  app.add_flag("-n", no_deadlock, "prevent a deadlock at all");
  app.add_flag("--nodeadlock", no_deadlock, "prevent a deadlock at all");
  app.add_flag("-l", live, "Simulate a livelock");
  app.add_flag("--lifelock", live, "Simulate a livelock");
  CLI11_PARSE(app, argc, argv);

  if (no_deadlock)
  {
    pointer = &s;
    cout << "NODEADLCOK" << endl;
  }
  else
  {
    pointer = nullptr;
  }
  cout << no_deadlock << endl;

  mutex gabel1;
  mutex gabel2;
  mutex gabel3;
  mutex gabel4;
  mutex gabel5;

  thread p1{Philosopher(1), ref(gabel1), ref(gabel2), ref(pointer), live};
  thread p2{Philosopher(2), ref(gabel2), ref(gabel3), ref(pointer), live};
  thread p3{Philosopher(3), ref(gabel3), ref(gabel4), ref(pointer), live};
  thread p4{Philosopher(4), ref(gabel4), ref(gabel5), ref(pointer), live};
  thread p5{Philosopher(5), ref(gabel5), ref(gabel1), ref(pointer), live};

  p1.join();
  p2.join();
  p3.join();
  p4.join();
  p5.join();

  return 0;
}
