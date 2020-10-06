#include <iostream>
#include <thread>
#include <random>
using namespace std;

void Golf6() {
    int i = 1;
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};
    double time{};

    while (true)
    {
        time = dis(gen);
        cout << to_string(i) << " " <<  " Golf6 " << time << "\n";
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time*1000)));      
        i++;
    }
}

class Car {
private:
    string carName;
  
public:
    void operator()() {
        int j = 1;
        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<> dis{1, 10};
        double time{};
    

        while (true)
        {
            time = dis(gen);
            cout << to_string(j) << " " << carName << " " << time << "\n";
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time*1000)));
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
