#include <iostream>
#include <thread>
#include <mutex>
#include "philosopher.h"

void Philosopher::operator()(mutex &fr, mutex &fl) {
  while (true) {
    cout << "Philosopher " << to_string(this->number) << " is thinking.." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "Philosopher " << this->number << " attemps to get left fork" << endl;
    fl.lock();
    cout << "Philosopher " << this->number << " got left fork. Now he wants the right one..." << endl;
    fr.lock();
    cout << "Philosopher " << this->number << " got right fork. Now he is eating..." << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Philosopher " << this->number << " finished eating" << endl;
    fr.unlock();
    cout << "Philosopher " << this->number << " released left fork" << endl;
    fl.unlock();
    cout << "Philosopher " << this->number << " released right fork" << endl;
  }
}