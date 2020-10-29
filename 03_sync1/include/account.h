#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mutex>
using namespace std;
class Account {
    private:
        int balance{0};
        mutex mtx;
    public:
        Account(int amount);
        int get_balance();

        void deposit(int amount);

        bool withdraw(int amount) ;


};

class Depositer {
    private:
    Account& acc;
    int deposits;

    public:
        Depositer(Account& a, int depos) : acc(a), deposits(depos){

        }
        void operator()() {
            for(int i = 0; i < deposits; i++) {
                acc.deposit(1);
            }
        }

};

#endif