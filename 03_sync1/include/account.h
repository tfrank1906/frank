#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    private:
        int balance{0};
    public:
        int get_balance();

        void deposit(int amount);

        bool withdraw(int amount) ;


};

class Depositer {
    private:
    Account& acc;

    public:
        Depositer(Account& a) : acc(a){

        }
        void operator()() {
            for(int i = 0; i < 5; i++) {
                acc.deposit(1);
            }
        }

};

#endif