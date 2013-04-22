#include "vector_container.h"
#include "gtest/gtest.h"

#include <cmath>
#include <cfloat>

#define SIZE 10

namespace {

float data[SIZE][4] = { 
    {0, 1, 2, 3}, 
    {1, 2, 3, 4}, 
    {2, 3, 4, 5}, 
    {3, 4, 5, 6}, 
    {4, 5, 6, 7}, 
    {5, 6, 7, 8}, 
    {6, 7, 8, 9}, 
    {7, 8, 9, 10}, 
    {8, 9, 10, 11}, 
    {9, 10, 11, 12}
};
 
TEST(VectorContainer, Subscript) {
  Vector vs[SIZE];
  for (int i = 0; i < SIZE; i++) {
    vs[i] = Vector(data[i]);
  }

  VectorContainer vc(vs, SIZE);
  
  for (int i = 1; i < SIZE; i++) {
    bool isright = (fabs((vc[i].v)[1] - data[i][1]) < FLT_EPSILON) | 
                   (fabs((vc[i].v)[1] - data[i - 1][1]) < FLT_EPSILON);
    EXPECT_TRUE(isright); 
  }
}

TEST(VectorContainer, Arrow) {
  Vector vs[SIZE];
  for (int i = 0; i < SIZE; i++) {
    vs[i] = Vector(data[i]);
  }

  VectorContainer vc(vs, SIZE);
  EXPECT_NEAR(vc->v[0], data[9][0], FLT_EPSILON);
}

TEST(VectorContainer, Bracket) {
  Vector vs[SIZE];
  for (int i = 0; i < SIZE; i++) {
    vs[i] = Vector(data[i]);
  }

  VectorContainer vc(vs, SIZE);
  for (int i = 1; i < SIZE; i++) {
    bool isright = (fabs((vc(i).v)[1] - data[i][1]) < FLT_EPSILON) | 
                   (fabs((vc(i).v)[1] - data[i - 1][1]) < FLT_EPSILON);
    EXPECT_TRUE(isright); 
  }
}

TEST(VectorContainer, Bracket2) {
  Vector vs[SIZE];
  for (int i = 0; i < SIZE; i++) {
    vs[i] = Vector(data[i]);
  }

  VectorContainer vc(vs, SIZE);
  bool isright = (fabs(vc(1, 1) - data[1][1]) < FLT_EPSILON) | 
                 (fabs(vc(1, 1) - data[0][0]) < FLT_EPSILON);
  EXPECT_TRUE(isright); 
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
