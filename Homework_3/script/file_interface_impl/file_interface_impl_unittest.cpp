#include "gtest/gtest.h"

#include "file_interface_impl.h"

TEST(FileInterfaceImpl, GetWordByPos_0) {
  FileInterfaceImpl fii("file.out");
  EXPECT_EQ(fii.GetWordByPos(0), "example");
}

TEST(FileInterfaceImpl, GetWordByPos_1) {
  FileInterfaceImpl fii("file.out");
  EXPECT_EQ(fii.GetWordByPos(1), "one");
}

TEST(FileInterfaceImpl, Operator_0) {
  FileInterfaceImpl fii("file.out");
  EXPECT_EQ(fii[0], "example");
}

TEST(FileInterfaceImpl, Operator_1) {
  FileInterfaceImpl fii("file.out");
  EXPECT_EQ(fii[0], "example");
}

TEST(FileInterfaceImpl, GetNext_0) {
  FileInterfaceImpl fii("file.out");
  EXPECT_TRUE(fii.GetNext());
}

TEST(FileInterfaceImpl, GetNext_1) {
  FileInterfaceImpl fii("file.out");
  fii.GetNext();
  fii.GetNext();
  EXPECT_FALSE(fii.GetNext());
}

TEST(FileInterfaceImpl, Word_0) {
  FileInterfaceImpl fii("file.out");
  fii.GetNext();
  EXPECT_EQ(fii.word(), "example");
} 

TEST(FileInterfaceImpl, Word_1) {
  FileInterfaceImpl fii("file.out");
  fii.GetNext();
  fii.GetNext();
  EXPECT_EQ(fii.word(), "one");
} 

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
