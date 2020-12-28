#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

class Clock {
    private: 
    string name;
    chrono::time_point<chrono::system_clock> curr_time;

    public:
    Clock(string name_){
        this->name = name_;
        curr_time = chrono::system_clock::now();
    }

    void operator()();

    


};
