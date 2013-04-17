#include "series_comp.h"
#include "gtest/gtest.h"

namespace {

TEST(SeriesCompTest, Sum_1) {
  util::SeriesComp sc_10(10);
  EXPECT_EQ(55, sc_10.sum()); 
}

TEST(SeriesCompTest, Sum_2) {
  util::SeriesComp sc_1(1);
  EXPECT_EQ(1, sc_1.sum());
}

TEST(SeriesCompTest, Sum_3) {
  util::SeriesComp sc_4(4);
  EXPECT_EQ(10, sc_4.sum());
}

TEST(SeriesCompTest, Fib_1) {
  util::SeriesComp sc(1);
  EXPECT_EQ(1, sc.fib());
}

TEST(SeriesCompTest, Fib_2) {
  util::SeriesComp sc_10(10);
  EXPECT_EQ(143, sc_10.fib());
}

TEST(SeriesCompTest, Fib_3) {
  util::SeriesComp sc_4(4);
  EXPECT_EQ(7, sc_4.fib());
}

TEST(SeriesCompTest, Taylor_1) {
  util::SeriesComp sc(1);
  EXPECT_NEAR(-9, sc.taylor(10), 0.01);
}

TEST(SeriesCompTest, Taylor_2) {
  util::SeriesComp sc(4);
  EXPECT_NEAR(291, sc.taylor(10), 0.01);
}

TEST(SeriesCompTest, Taylor_3) {
  util::SeriesComp sc(10);
  EXPECT_NEAR(1342.59, sc.taylor(10), 0.01);
}

}
