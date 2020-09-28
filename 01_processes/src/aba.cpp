#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <csignal>
#include <sys/wait.h>

using namespace std;

int main() {
    int status;
    cout << "waiting for 3 seconds" << endl;
    
    auto pid{fork()};
    
    if (pid == 0) {
        execl("/home/tobias/01_processes/build/charout", "charout",
              "A", nullptr);
             

        if (errno == 2) {
            cout << "Nicht erfolgreich!" << endl;
          
        }
    }

    else {
        auto pid2{fork()};
        if (pid2 == 0) {
            execl("/home/tobias/01_processes/build/charout", "charout",
                  "B", nullptr);

            if (errno == 2) {
                cout << "Nicht erfolgreich!" << endl;
            
            }
            
        
        }
        
      
        chrono::milliseconds sleeptime(3000);
        this_thread::sleep_for(sleeptime);

        cout << "\nkilling both subprocesses with pids " << pid2 << " and " << pid << endl;
        cout << "waiting for both subprocesses to be dead" << endl;

        kill(pid, SIGKILL);
        kill(pid2, SIGKILL);

        waitpid(pid, &status, 0);
        cout << "subprocess terminated w/ exit code "<< status << endl;

        waitpid(pid2, &status, 0);
        cout << "subprocess terminated w/ exit code "<< status << endl;
    }
}
