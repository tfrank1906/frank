#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <initializer_list>
#include <chrono>
#include "philosopher.h"
#include "semaphore.h"
#include "utils.h"
using namespace std;

void Philosopher::operator()(mutex &fr, mutex &fl, Semaphore *s, bool live)
{
  if (live)
  {
    println("Philosopher ", to_string(this->number), " is thinking..");
    this_thread::sleep_for(chrono::milliseconds(1000));

    println("Philosopher ", to_string(this->number), " attemps to get left fork");

    fl.lock();

    println("Philosopher ", to_string(this->number), " got left fork. Now he wants the right one...");
    this_thread::sleep_for(chrono::milliseconds(3000));
    println("Philosopher ", to_string(this->number), " got left fork. Now he wants the right one...");

    bool lock = fr.try_lock();
    fl.unlock();

    println("Philosopher ", to_string(this->number), " got right fork. Now he is eating...");

    this_thread::sleep_for(chrono::milliseconds(2000));
    println("Philosopher ", to_string(this->number), " finished eating");

    if (lock)
    {
      fr.unlock();
    }

    println("Philosopher ", to_string(this->number), " released right fork");

    println("Philosopher ", to_string(this->number), " released left fork");
  }
  if (s == nullptr)
  {
    while (true)
    {
      println("Philosopher ", to_string(this->number), " is thinking..");

      this_thread::sleep_for(chrono::milliseconds(1000));
      println("Philosopher ", to_string(this->number), " attemps to get left fork");

      fl.lock();
      println("Philosopher ", to_string(this->number), " got left fork. Now he wants the right one...");
      this_thread::sleep_for(chrono::milliseconds(5000));

      fr.lock();
      println("Philosopher ", to_string(this->number), " got right fork. Now he is eating...");

      this_thread::sleep_for(chrono::milliseconds(2000));
      println("Philosopher ", to_string(this->number), " finished eating");
      fr.unlock();
      println("Philosopher ", to_string(this->number), " released left fork");
      fl.unlock();
    }
  }
  else
  {
    while (true)
    {
      println("Philosopher ", to_string(this->number), " is thinking..");

      this_thread::sleep_for(chrono::milliseconds(1000));
      println("Philosopher ", to_string(this->number), " attemps to get left fork");
      s->acquire();
      fl.lock();
      println("Philosopher ", to_string(this->number), " got left fork. Now he wants the right one...");
      this_thread::sleep_for(chrono::milliseconds(5000));
      s->release();
      fr.lock();
      println("Philosopher ", to_string(this->number), " got right fork. Now he is eating...");

      this_thread::sleep_for(chrono::milliseconds(2000));
      println("Philosopher ", to_string(this->number), " finished eating");
      fl.unlock();
      println("Philosopher ", to_string(this->number), " released left fork");
      s->release();
      fr.unlock();
      println("Philosopher ", to_string(this->number), " released left fork");
    }
  }
}
