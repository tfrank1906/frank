#include <iostream>
#include <thread>
#include "account.h"

using namespace std;

int Account::get_balance(){
    return this->balance;
}

void Account::deposit(int amount){
    balance += amount;
}

bool Account::withdraw(int amount){
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    else {
        return false;
    }
}
