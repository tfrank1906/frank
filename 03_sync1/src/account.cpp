#include <iostream>
#include <thread>
#include <mutex>
#include "account.h"

using namespace std;

Account::Account(int amount){
    balance = amount;
}

int Account::get_balance(){
    return this->balance;
}

void Account::deposit(int amount){
    unique_lock<mutex> lock(mtx, defer_lock);
    balance += amount;
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
