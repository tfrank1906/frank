#include <iostream>
#include <thread>

#include "account.h"

using namespace std;

int main(){
   Account a;
   cout << a.get_balance() << endl;

   a.deposit(15);
   cout << a.get_balance() << endl;

   a.withdraw(6);
   cout << a.get_balance() << endl;

   cout << a.withdraw(10) << endl;
   cout << a.get_balance() << endl;
}
