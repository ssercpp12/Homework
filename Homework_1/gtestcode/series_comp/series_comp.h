#ifndef SERIES_COMP_H_
#define SERIES_COMP_H_

namespace util {

class SeriesComp {
 public:
  SeriesComp(int n);
  int sum();
  int fib();
  double taylor(double x);

 private:
  int n_;
};

}

#endif
