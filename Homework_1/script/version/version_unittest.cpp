#include "version.h"

#include "gtest/gtest.h"

#define ARRAYSIZE_UNSAFE(a) \
  ((sizeof(a) / sizeof(*(a))) / \
   static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

namespace {

static const struct version_compare {
  const char* lhs;
  const char* rhs;
  int expected;
} cases[] = {
  {"1.0", "1.0", 0},
  {"1.0", "0.0", 1},
  {"1.0", "2.0", -1},
  {"1.0", "1.1", -1},
  {"1.1", "1.0", 1},
  {"1.0", "1.0.1", -1},
  {"1.1", "1.0.1", 1},
  {"1.1", "1.0.1", 1},
  {"1.0.0", "1.0", 0},
  {"1.0.3", "1.0.20", -1},
};

TEST(VersionTest, ValueSemantics_1) {
  Version v1("1.2.3.4");
  EXPECT_TRUE(v1.IsValid());
}

TEST(VersionTest, ValueSemantics_2) {
  Version v1("*.2.3.4");
  EXPECT_FALSE(v1.IsValid());
}

TEST(VersionTest, ValueSemantics_3) {
  Version v1(""); 
  EXPECT_FALSE(v1.IsValid());
}

TEST(VersionTest, ValueSemantics_4) {
  Version v1("10.1.0"); 
  EXPECT_TRUE(v1.IsValid());
}

TEST(VersionTest, ValueSemantics_5) {
  static const struct version_string {
    const char* input;
    size_t parts;
    bool success;
  } cases[] = {
    {"", 0, false},
    {" ", 0, false},
    {"\t", 0, false},
    {"\n", 0, false},
    {"  ", 0, false},
    {".", 0, false},
    {" . ", 0, false},
    {"0", 1, true},
    {"0.0", 2, true},
    {"-1.0", 0, false},
    {"1.-1.0", 0, false},
    {"+1.0", 0, false},
    {"1.+1.0", 0, false},
    {"1.0a", 0, false},
    {"1.2.3.4.5.6.7.8.9.0", 10, true},
    {"f.1", 0, false},
  };

  for (size_t i = 0; i < ARRAYSIZE_UNSAFE(cases); ++i) {
    Version version(cases[i].input);
    EXPECT_EQ(cases[i].success, version.IsValid());
  }
}

TEST(VersionTest, Compare_0) {
  int i = 0;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_1) {
  int i = 1;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_2) {
  int i = 2;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_3) {
  int i = 3;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_4) {
  int i = 4;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_5) {
  int i = 5;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_6) {
  int i = 6;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_7) {
  int i = 7;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_8) {
  int i = 8;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

TEST(VersionTest, Compare_9) {
  int i = 9;
  Version lhs(cases[i].lhs);
  Version rhs(cases[i].rhs);
  EXPECT_EQ(lhs.CompareTo(rhs), cases[i].expected) <<
      cases[i].lhs << " ? " << cases[i].rhs;
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
