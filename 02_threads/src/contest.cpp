#include <iostream>
#include <thread>
using namespace std;

void Golf6 () {
    int i = 1;
    while (true) {
        cout << i << " Golf6" << endl;
        this_thread::sleep_for(1s);
        i++;
    }
}

int main() {
    thread t{Golf6}; 
    t.join();
    cout << t.joinable() << endl;   
}
