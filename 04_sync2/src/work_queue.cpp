#include <iostream>
#include <thread>
#include <mutex>

#include "work_packet.h"
#include "work_queue.h"


WorkQueue::WorkQueue(){}

WorkPacket WorkQueue::push(WorkPacket wp){

    lock_guard<mutex> guard{mtx};
    WQ.push(wp);
    return wp;
}

WorkPacket WorkQueue::pop(){
   
    lock_guard<mutex> guard{mtx};
    WorkPacket wp = WQ.front();
    WQ.pop();
    return wp;
}