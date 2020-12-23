#include <mutex>
#include "semaphor.h"


using namespace std;

void Semaphore::acquire(){
    unique_lock<mutex> lck{mtx};
    
    this->data_ready.wait(lck, [this] {return this->i;});
    this->i -= 1;


}

void Semaphore::release(){
    lock_guard<mutex> lck{mtx};
    this->i += 1;
    this->data_ready.notify_all();
    
}

int Semaphore::availabe_permits (){
    lock_guard<mutex> lck {mtx};
    return this->i;
}