#include <iostream>
#include <thread>
#include <sstream>
#include <chrono>
#include <random>


#include "work_packet.h"
#include "work_queue.h"

using namespace std;

void worker(int id, WorkQueue& q){
  random_device rd;
  mt19937 eng{rd()};
  uniform_real_distribution<> distr(1,10);
  double time;

  stringstream buf;

  while(true){
    time = distr(eng);
    buf << "W" << id << ": Want work packet" << endl;
    WorkPacket wpdel = q.pop();
    
    buf << "W" << id << ": Got work packet " << wpdel.get_id() << endl; 
    this_thread::sleep_for(chrono::milliseconds(1000));
    buf << "W" << id << ": Processed work packet " << wpdel.get_id() << "("  << time << "s)" << endl;
    cout << buf.str();
    buf.str("");
  }

}

int main() {
  random_device rd;
  mt19937 eng{rd()};
  uniform_real_distribution<> distr(0,1);
  
  double time;
  int i{0};
  WorkQueue a;

  thread t1{[&]  {worker(1, a);}};
  //thread t2{[&]  {worker(2, a);}};

  stringstream buf;
  while (true) {
    time = distr(eng);
    WorkPacket wp{i};
    a.push(wp);
    buf << "B : Waiting to submit work packet " << wp.get_id() << endl;
    
    this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time*1000)));
    buf << "W" << ": Processed work packet " << wp.get_id() << "("  << time << "s)" << endl;
    cout << buf.str();
    buf.str("");
    i++;
  }
 
  t1.join();
  //t2.join();




  return 0;
}
