#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <vector>
#include <future>
#include <chrono>

#include "CLI11.hpp"

//inkludierung der Headerfile laut ReadMe
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop

#include "calc_factors.h"

using namespace std;

void print_res(vector<InfInt> &zahlen, vector<shared_future<vector<InfInt>>> &ergebnisse){
  vector<InfInt> a;
  auto start = chrono::system_clock::now();
  for (size_t i = 0; i < zahlen.size(); i++){
    cout << zahlen[i] << ": ";
    a = ergebnisse[i].get();
    for (size_t j = 0; j < a.size(); j++){
      cout << a[j] << " ";
    }
    cout << endl;
  }
  auto duration = chrono::duration_cast<chrono::milliseconds>(std::chrono::system_clock::now() - start);
  cout << "Time elapsed for factoring: " << duration.count() << "ms" << endl;
}

void check_res(vector<InfInt> &zahlen, vector<shared_future<vector<InfInt>>> &ergebnisse){
  vector<InfInt> a;
  InfInt res = 0;
  InfInt zahl;
  for (size_t i = 0; i < zahlen.size(); i++){
    res = 0;
    zahl = zahlen[i];
    a = ergebnisse[i].get();
    for (size_t j = 0; j < a.size(); j++){
      if(res == 0){
        res += a[j];
      }
      else {
         res *= a[j];
      }
    }
    if(zahl != res){
      cerr << "Fehler bei Faktorisierung von Zahl! Es kommt raus: " << res << endl;
     } 
  }
}

int main(int argc, const char *argv[]){
  bool asyncbool{false};
  vector<string> v1;
  CLI::App app("factoring");
  app.add_option("number", v1, "numbers to factor");
  app.add_option("--async", asyncbool, "async");
  CLI11_PARSE(app, argc, argv);

  vector<InfInt> v2;
  for (size_t n = 0; n < v1.size(); n++){
    v2.push_back(v1[n]);
  }
  InfInt curr;
  vector<shared_future<vector<InfInt>>> results;
  for (size_t i = 0; i < v2.size(); i++){
    curr = v2[i];
    if(asyncbool){
      results.push_back(async(launch::async, get_factors, curr).share());
    }
    else {
      results.push_back(async(get_factors, curr).share());
    }
    
  }
  
  thread t1(print_res, ref(v2), ref(results)); 
  thread t2(check_res, ref(v2), ref(results)); 
  t1.join();
  t2.join();
}


