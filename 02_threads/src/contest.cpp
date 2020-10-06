#include <iostream>
#include <thread>
#include <random>
#include <iomanip>
#include <sstream>
using namespace std;

int Golf6(double& alltime) {
    ostringstream bufstr;
    int i = 1;
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};
    double time{};

    while (i <= 10)
    {
        time = dis(gen);
        bufstr << to_string(i) << " " << "Golf6R" << " " << setprecision(3)   << time << endl;
        cout << bufstr.str();
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time*1000)));      
        i++;
        bufstr.str(""); 
        alltime += time;
    }
    return alltime;
}


class Car {
private:
    string carName;
    double alltime{};
  public:
    void operator()() {
        ostringstream bufstr;
        int j = 1;
        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<> dis{1, 10};
        double time{};
        

        while (j <= 10)
        {
            time = dis(gen);
            bufstr << to_string(j) << " " << carName << " " << setprecision(3)  << time << endl;
            cout << bufstr.str();
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time*1000)));
            j++;
            bufstr.str(""); 
            alltime += time;
        }
    }


    Car(string name) {
        this->carName = name;
    
    }

    double get_total_time() {
       return this->alltime;
    
    }



};

 int main() {
    double alltimeclass;
    double alltime;

    thread t{Golf6, ref(alltime)};
   

    Car bmw("BMWE46");
  
    thread t2 {ref(bmw)};
    t.join();
    t2.join();

    alltimeclass = bmw.get_total_time();
    
    if (alltime > alltimeclass){
        cout << "Sieger ist BMW E46 mit: " << alltimeclass << "s" << endl;
        cout << "Verlierer ist Golf6 mit: " << alltime << "s" << endl;
    } else {
        cout << "Sieger ist Golf6 mit: " << alltime << "s" << endl;
        cout << "Verlierer ist Golf6 mit: " << alltimeclass << "s" << endl;
    }
}
