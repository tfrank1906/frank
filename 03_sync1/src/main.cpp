#include <iostream>
#include <thread>

#include "account.h"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char *argv[])
{

  CLI::App app("Account app");
  int balance{0};
  app.add_option("balance", balance, "Initial balance")->required();
  int deposits{5};
  app.add_option("-d,--deposits", deposits, "Count of deposits", true);
  CLI11_PARSE(app, argc, argv);
  Account a{balance};
  Depositer depo(a, deposits);

  thread t1(ref(depo));

  thread t2(ref(depo));

  t1.join();
  t2.join();

  cout << a.get_balance() << endl;

  /*
   Punkt 5
   cout << a.get_balance() << endl;

   a.deposit(1);
   cout << a.get_balance() << endl;

   //Punkt 1
   
   Account a;
   cout << a.get_balance() << endl;

   a.deposit(15);
   cout << a.get_balance() << endl;

   a.withdraw(6);
   cout << a.get_balance() << endl;

   cout << a.withdraw(10) << endl;
   cout << a.get_balance() << endl;
   */

  /*
  Punkt 5
  thread t1{[&]  {cout << a.withdraw(1) << endl;}};
  thread t2{[&]  {cout << a.withdraw(1) << endl;}};
 
  t1.join();
  t2.join();
  */


}
