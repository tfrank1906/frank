#include <iostream>
#include <thread>
#include <vector>
#include <string>

#include "CLI11.hpp"

//inkludierung der Headerfile laut ReadMe
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop

#include "calc_factors.h"

using namespace std;

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
  
  vector<InfInt> vtemp;
  for (size_t i = 0; i < v2.size(); i++){
    cout << v2[i] << ": ";
    vtemp = (get_factors(v2[i]));
  
    for (size_t j = 0; j < vtemp.size(); j++){
       cout << vtemp[j] << " ";
    }
    cout << endl;
  }

  return 0;
}
