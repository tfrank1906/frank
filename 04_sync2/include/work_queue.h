#pragma once 
#include <mutex>
#include <queue>
#include "work_packet.h"
using namespace std;



class WorkQueue {
    private:
        queue <WorkPacket> WQ;
        mutex mtx;
    public:
        WorkQueue();

        WorkPacket push(WorkPacket wp);
        
        void pop();

    
};

    

