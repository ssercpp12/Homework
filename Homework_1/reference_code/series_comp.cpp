#include "series_comp.h"

namespace util {

SeriesComp::SeriesComp(int n) : n_(n) {}

int SeriesComp::sum() {
  int sum = 0;
  for (int i = 1; i <= n_; ++i) {
    sum += i;
  }

  return sum;
}

int SeriesComp::fib() {
  int prea, preb, ans, temp;
  prea = preb = 1;
  if(n_ == 1 || n_ == 2)
    return n_;
  ans = 2;
  for (int i = 3; i <= n_; i++) {
    temp = prea;
    prea = preb;
    preb = temp + preb;
    ans += preb;
  }

  return ans;
}

double SeriesComp::taylor(double x) {
  double ans, powx, fac;
  ans = powx = fac = 1.0;
  for(int i = 1; i <= n_; i++) {
    powx *= x;
    fac *= i;
    if(i % 2 == 1) {
      ans -= powx / fac;
    } else {
      ans += powx / fac;
    }
  }
  return ans;
}

} // namespace util
