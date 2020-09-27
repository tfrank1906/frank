#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <csignal>
#include <sys/wait.h> 

using namespace std;

int main() {
    auto pid{fork()};
    if (pid == 0) {
        while (true)
        {
            cout << "A" << endl;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }

    }

    else {
        for (int i = 0; i < 6; i++) {
            cout << "B" << endl;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }

       kill(0, SIGKILL);
       int status;
       waitpid(0, &status, 0);
        

        
    }
}
