#pragma once 
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <initializer_list>
#include "semaphor.h"

using namespace std;

class Philosopher{
    private:
        int number;
    public:
        Philosopher(int number){
            this->number = number;
        }
        void operator()(mutex &fr, mutex &fl, Semaphore *s, bool live);
 
      
        int get_id(){
            return this->number;
        }
        

};
