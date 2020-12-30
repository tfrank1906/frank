#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include "timeutils.h"
#include "utils.h"
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
    Clock(string name_, int hours_, int minutes_, int seconds_){
        this->name = name_;
        curr_time = chrono::system_clock::now();
        curr_time = timeutils::set_time(curr_time, hours_, minutes_, seconds_);
    }

    void operator()();

    void set_time(int hours, int minutes, int seconds);

    tuple<int, int, int> get_time();

    


};
