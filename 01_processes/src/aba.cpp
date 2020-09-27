#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
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
        while (true) {
            cout << "B" << endl;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }
    }
}
