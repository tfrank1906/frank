#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <initializer_list>

#include "philosopher.h"
using namespace std;
int main() {

    mutex gabel1;
    mutex gabel2;
    mutex gabel3;
    mutex gabel4;
    mutex gabel5;
    
    
   

    thread p1{Philosopher(1), ref(gabel1), ref(gabel2)};
    thread p2{Philosopher(2), ref(gabel2), ref(gabel3)};
    thread p3{Philosopher(3), ref(gabel3), ref(gabel4)};
    thread p4{Philosopher(4), ref(gabel4), ref(gabel5)};
    thread p5{Philosopher(5), ref(gabel5), ref(gabel1)};



    p1.join();
    p2.join();
    p3.join();
    p4.join();
    p5.join();




  return 0;
}

