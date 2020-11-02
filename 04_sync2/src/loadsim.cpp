#include <iostream>
#include <thread>

#include "work_packet.h"
#include "work_queue.h"

using namespace std;

int main() {
  int i{0};
  WorkQueue a;
  
  while (true) {
    WorkPacket wp{i};
    a.push(wp);
    cout << "Submitted work packet " << wp.get_id() << endl;
    i++;
    this_thread::sleep_for(chrono::milliseconds(500));
  }

  return 0;
}
