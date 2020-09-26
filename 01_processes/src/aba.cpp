#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    auto pid{fork()};
    if (pid == 0) {
        while (true)
        {
            cout << "A" << endl;
            sleep(0.5);
        }
    }

    else {
        while (true) {
            cout << "B" << endl;
            sleep(0.5);
        }
    }
}
