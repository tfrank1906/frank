#pragma once 
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore{
    private:
        int i;
        condition_variable data_ready;
        mutex mtx;
    public:
        
        void acquire();
        void release();
        int availabe_permits();
        Semaphore(int permits){
            this->i = permits;
        }

};