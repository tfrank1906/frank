#include <iostream>
#include <thread>
#include <mutex>

#include "work_packet.h"
#include "work_queue.h"




WorkPacket WorkQueue::push(WorkPacket wp){

    unique_lock<mutex> lck{mtx};
    pushcond.wait(lck, [this]{return WQ.size() < size;});
    WQ.push(wp);
    popcond.notify_one();
    return wp;
}

WorkPacket WorkQueue::pop(){
   
    unique_lock<mutex> lck{mtx};
    popcond.wait(lck, [this]{return WQ.size();});
    WorkPacket wp = WQ.front();
    WQ.pop();
    pushcond.notify_one();
    return wp;
}