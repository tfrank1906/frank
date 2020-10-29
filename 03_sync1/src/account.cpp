#include <iostream>
#include <thread>
#include <mutex>
#include "account.h"

using namespace std;

int Account::get_balance(){
    return this->balance;
}

void Account::deposit(int amount){
    int tmo{balance};
    std::this_thread::sleep_for(10ms);
    balance = tmp + amount;
}

bool Account::withdraw(int amount){
    mutex m;
    lock_guard<mutex> guard{m};
    if (balance - amount >= 0) {
        this_thread::yield();
        balance -= amount;
        return true;
    }
    else {
        return false;
    }
}
