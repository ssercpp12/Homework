#ifndef  VECTOR_CONTAINER_H_
#define  VECTOR_CONTAINER_H_

#include <iostream>
using namespace std;

struct Vector {
  float v[4];

  Vector() {
    for (int i = 0; i < 4 ;++i) {
      v[i] = 0;
    }
  }

  Vector(float ve[]) {
    for (int i = 0; i < 4; ++i) {
      v[i] = ve[i];
    }
  }

  void output() {
    // TODO: Implement me.
  }
};

class VectorContainer {
 public:
  VectorContainer();

  // Copy Constructor, need deep copy.
  VectorContainer(const VectorContainer& other);
  VectorContainer(Vector *vectors, int size);
  
  ~VectorContainer();

  Vector& operator[](int index);
  Vector* operator->();
  void operator()();
  Vector& operator()(int i);
  float operator()(int i, int j);

 private:
  // This is a pointer point to a array of Vector.
  Vector* vectors_;

  // The size of the array of Vector.
  int size_;
};

#endif  /*VECTOR_CONTAINER_H*/
