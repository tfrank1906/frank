#include <iostream>
#include <thread>
#include <sstream>
#include <chrono>
#include <random>

#include "work_packet.h"
#include "work_queue.h"
#include "CLI11.hpp"


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
    this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time*1000)));
    buf << "W" << id << ": Processed work packet " << wpdel.get_id() << "("  << time << "s)" << endl;
    cout << buf.str();
    buf.str("");
  }

}

int main(int argc, char* const argv[]) {
  size_t max;

  random_device rd;
  mt19937 eng{rd()};
  uniform_real_distribution<> distr(0,1);
  double time;
  
  CLI::App app{"Boss and worker Simulation"};
  app.add_option("size", max, "Size of the queue")->required();
  CLI11_PARSE(app, argc, argv);
  WorkQueue a{max};
  

  thread t1{[&]  {worker(1, a);}};
  thread t2{[&]  {worker(2, a);}};
  thread t3{[&]  {worker(3, a);}};

  stringstream buf;
  int i{0};
  while (true) {
    time = distr(eng);
    WorkPacket wp{i};
    buf << "B : Waiting to submit work packet " << wp.get_id() << endl;
    a.push(wp);
    this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time*1000)));
    buf << "B : Submitted work packet " << wp.get_id() << "("  << time << "s)" << endl;
    cout << buf.str();
    buf.str("");
    i++;
  }
 
  t1.join();
  t2.join();
  t3.join();




  return 0;
}
