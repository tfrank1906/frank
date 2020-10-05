#include <iostream>
#include <thread>
using namespace std;

void Golf6() {
    int i = 1;
    while (true)
    {
        cout << to_string(i) << " Golf6\n";
        this_thread::sleep_for(1s);
        i++;
    }
}
class Car {
private:
    string carName;
  

public:
    void operator()() {
        int j = 1;
        while (true)
        {
            cout << to_string(j) << " " << carName << "\n";
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
