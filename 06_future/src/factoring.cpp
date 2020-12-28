#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <vector>
#include <future>

#include "CLI11.hpp"

//inkludierung der Headerfile laut ReadMe
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop

#include "calc_factors.h"

using namespace std;

void print_res(vector<InfInt> &zahlen, vector<future<vector<InfInt>>> &ergebnisse){
  vector<InfInt> a;
  for (size_t i = 0; i < zahlen.size(); i++){
    cout << zahlen[i] << ": ";
    a = ergebnisse[i].get();
    for (size_t j = 0; j < a.size(); j++){
      cout << a[j] << " ";
    }
    cout << endl;
  }
}

int main(int argc, const char *argv[])
{
  vector<string> v1;
  CLI::App app("factoring");
  app.add_option("number", v1, "numbers to factor");
  app.add_option("--async", v1, "async");
  CLI11_PARSE(app, argc, argv);

  vector<InfInt> v2;
  for (size_t n = 0; n < v1.size(); n++)
  {
    v2.push_back(v1[n]);
  }
  InfInt curr;
  vector<future<vector<InfInt>>> results;
  for (size_t i = 0; i < v2.size(); i++)
  {
    curr = v2[i];
    results.push_back(async(get_factors, curr));
  }
  
  thread t1(print_res, ref(v2), ref(results)); 
  t1.join();
}


