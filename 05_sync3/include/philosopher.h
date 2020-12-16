#pragma once 
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Philosopher{
    private:
        int number;
    public:
        Philosopher(int number){
            this->number = number;
        }
        void operator()(mutex &fr, mutex &fl);
        int get_id(){
            return this->number;
        }

};
