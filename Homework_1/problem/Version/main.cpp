#include <iostream>
#include <string>

#include "version.h"

using namespace std;

int main(int argc, char *argv[]) {
  // You can add any code to test your implement of Version here.
  string v1_str;
  string v2_str;
  
  cin >> v1_str >> v2_str;
  
  Version v1(v1_str);
  Version v2(v2_str);

  cout << v1.CompareTo(v2) << endl;

  return 0;
}
