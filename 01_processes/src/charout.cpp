#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <csignal>
#include <sys/wait.h> 

using namespace std;

int main(int argc, char* argv[]) {
    while (true) {
        cout << argv[1] << endl;
        
        chrono::milliseconds sleeptime(500);
        this_thread::sleep_for(sleeptime);
    }
    
}
