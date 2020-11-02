#include <iostream>
#include <thread>

#include "work_packet.h"
#include "work_queue.h"


using namespace std;

int main(){
  WorkQueue a;
  WorkPacket wp1{1};
  cout << wp1.get_id() << endl;
  a.push(wp1); 


return 0;
}
