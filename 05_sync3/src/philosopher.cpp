#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <initializer_list>
#include "philosopher.h"
#include "utils.h"
using namespace std;

void Philosopher::operator()(mutex &fr, mutex &fl)
{
  while (true)
  {
    println("Philosopher ", to_string(this->number), " is thinking..");

    this_thread::sleep_for(chrono::milliseconds(1000));
    println("Philosopher ", to_string(this->number), " attemps to get left fork");
    fl.lock();
    println("Philosopher ", to_string(this->number), " got left fork. Now he wants the right one...");
    fr.lock();
    println("Philosopher ", to_string(this->number), " got right fork. Now he is eating...");

    this_thread::sleep_for(chrono::milliseconds(2000));
    println("Philosopher ", to_string(this->number), " finished eating");
    fr.unlock();
    println("Philosopher ", to_string(this->number), " released left fork");
  }
}

