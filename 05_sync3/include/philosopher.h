#pragma once 
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>

using namespace std;

class Philosopher{
    private:
        int number;
    public:
        Philosopher(int number){
            this->number = number;
        }
        void operator()(mutex &fr, mutex &fl);
        void println(const vector<string>& a);
        int get_id(){
            return this->number;
        }

};
