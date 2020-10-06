#include <iostream>
#include <thread>
#include <random>
#include <iomanip>
#include <sstream>
using namespace std;

void Golf6() {
    ostringstream bufstr;
    int i = 1;
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};
    double time{};

    while (true)
    {
        time = dis(gen);
        bufstr << to_string(i) << " " << " Golf6 " << " " << setprecision(3)   << time << endl;
        cout << bufstr.str();
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time*1000)));      
        i++;
        bufstr.str(""); 
    }
}


class Car {
private:
    string carName;
  public:
    void operator()() {
        ostringstream bufstr;
        int j = 1;
        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<> dis{1, 10};
        double time{};
    

        while (true)
        {
            time = dis(gen);
        
            bufstr << to_string(j) << " " << carName << " " << setprecision(3)   << time << endl;
            cout << bufstr.str();
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time*1000)));
            j++;
            bufstr.str(""); 
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
