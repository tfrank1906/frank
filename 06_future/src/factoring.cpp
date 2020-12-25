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

using namespace std;

int main(int argc, const char *argv[])
{
  vector<string> v1;
  CLI::App app("factoring");
  app.add_option("number" , v1, "numbers to factor");
  app.add_option("--async", v1, "async");

  CLI11_PARSE(app, argc, argv);

  vector<InfInt> v2;

  for (size_t n = 0; n < v1.size(); n++){
    v2.push_back(n);
    cout << v1[n] << endl;  
  }

  return 0;
}
