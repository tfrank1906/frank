#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <cstdlib>
#include <sys/wait.h>
#include "CLI11.hpp"

using namespace std;

int main()
{
  int i = 1;
  while (i < 5)
  {

    auto pid{fork()};
    if (pid == -1)
    {
      cerr << "forking failed : " << errno << endl;
      exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
      cout << "I am Prozess: "<< i << endl;
      cout << "parent id is " << getppid() << endl;
      sleep(3);
      quick_exit(EXIT_SUCCESS);
    }
    else
    {
      cout << "child pid is " << pid << endl;
      int status;
      waitpid(pid, &status, 0);
      cout << "child terminated w / exit code " << status << endl;
      
    }
    i++;
  }
}