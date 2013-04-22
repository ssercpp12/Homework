#include "singleton2.h"
#include "gtest/gtest.h"

TEST(Singleton2, Singleton2Test) {
  Singleton& a = Singleton::GetInstance();
  Singleton& b = Singleton::GetInstance();
  a.SetValue(10);
  b.SetValue(100);
  ASSERT_EQ(100, Singleton::GetInstance().GetValue());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
