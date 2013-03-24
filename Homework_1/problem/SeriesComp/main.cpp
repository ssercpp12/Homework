#include <iostream>
#include "series_comp.h"

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    util::SeriesComp sc(n);

    cout << "Sum: " << sc.sum() << endl;
    cout << "Fib: " << sc.fib() << endl;
    cout << "Taylor: " << sc.taylor(10) << endl;
  }
  return 0;
}
