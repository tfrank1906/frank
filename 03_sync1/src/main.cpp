#include <iostream>
#include <thread>

#include "account.h"

using namespace std;

int main(){
   Account a;
   cout << a.get_balance() << endl;

   a.deposit(1);
   cout << a.get_balance() << endl;

   //Punkt 1
   /*
   Account a;
   cout << a.get_balance() << endl;

   a.deposit(15);
   cout << a.get_balance() << endl;

   a.withdraw(6);
   cout << a.get_balance() << endl;

   cout << a.withdraw(10) << endl;
   cout << a.get_balance() << endl;
   */

  thread t1{[&]  {cout << a.withdraw(1) << endl;}};
  thread t2{[&]  {cout << a.withdraw(1) << endl;}};
 
  t1.join();
  t2.join();



}