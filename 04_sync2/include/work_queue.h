#pragma once 
#include <mutex>
#include <queue>
#include <condition_variable>
#include "work_packet.h"
using namespace std;



class WorkQueue {
    private:
        queue <WorkPacket> WQ;
        mutex mtx;
        size_t size;
        condition_variable pushcond;
        condition_variable popcond;
    public:
        WorkQueue(size_t max){
            size = max;
        }

        WorkPacket push(WorkPacket wp);
        
        WorkPacket pop();

    
};

    

