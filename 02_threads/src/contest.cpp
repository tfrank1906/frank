#include <iostream>
#include <thread>
using namespace std;

void Golf6() {
    int i = 1;
    while (true)
    {
        cout << i << " Golf6" << endl;
        this_thread::sleep_for(1s);
        i++;
    }
}
class Car {
private:
    string carName;
    int runden;

public:
    void operator()() {
        int j = 1;
        while (true)
        {
            cout << j << " " << carName << endl;
            this_thread::sleep_for(1s);
            j++;
        }
    }

    Car(string name) {
        this->carName = name;
    
    }

};

 int main() {
    thread t{Golf6};
    Car bmw("BMWE46");
    thread t2 {ref(bmw)};
    t.join();
    t2.join();
    cout << t.joinable() << endl;
}
