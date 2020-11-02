#include <iostream>
#include <thread>
#include <mutex>

#include "work_packet.h"
#include "work_queue.h"


WorkQueue::WorkQueue(){}

WorkPacket WorkQueue::push(WorkPacket wp){
    mutex m;
    lock_guard<mutex> guard{m};
    WQ.push(wp);
    return wp;
}

WorkPacket WorkQueue::pop(){
    mutex m;
    lock_guard<mutex> guard{m};
    WorkPacket wp = WQ.front();
    WQ.pop();
    return wp;
}