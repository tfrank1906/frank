#include <iostream>
#include <thread>
#include <sstream>

#include "work_packet.h"
#include "work_queue.h"

using namespace std;

void worker(int id, WorkQueue& q){

  stringstream buf;

  while(true){
    buf << "W" << id << ": Want work packet" << endl;
    WorkPacket wpdel = q.pop();
    
    buf << "W" << id << ": Got work packet " << wpdel.get_id() << endl; 
    this_thread::sleep_for(chrono::milliseconds(1000));
    buf << "W" << id << ": Processed work packet " << wpdel.get_id() << endl;
    cout << buf.str();
    buf.str("");
  }

}

int main() {
 
  int i{0};
  WorkQueue a;

  thread t1{[&]  {worker(1, a);}};
  //thread t2{[&]  {worker(2, a);}};

  stringstream buf;
  while (true) {
    WorkPacket wp{i};
    a.push(wp);
    buf << "B : Submitted work packet " << wp.get_id() << endl;
    i++;
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << buf.str();
    buf.str("");
  }
 
  t1.join();
  //t2.join();




  return 0;
}
