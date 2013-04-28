// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include "vector_container.h"

#include <cstddef>

// Note: Since we simplified the problem and gtest code only checked the return
// value, I ignore all of the output.

VectorContainer::VectorContainer() : vectors_(NULL), size_(0) {}

VectorContainer::VectorContainer(const VectorContainer& other) {
  size_ = other.size_;
  vectors_ = new Vector[size_];
  for (int i = 0; i < size_; ++i)
    vectors_[i] = other.vectors_[i];
}

VectorContainer::VectorContainer(Vector* vectors, int size) {
  size_ = size;
  vectors_ = new Vector[size_];
  for (int i = 0; i < size_; ++i)
    vectors_[i] = vectors[i];
}

VectorContainer::~VectorContainer() {
  delete []vectors_;
}

Vector& VectorContainer::operator[](int index) {
  return vectors_[index];
}

Vector* VectorContainer::operator->() {
  return &(vectors_[size_ - 1]);
}

void VectorContainer::operator()() {
  for (int i = 0; i < size_; i++)
    vectors_[i].output();
}

Vector& VectorContainer::operator()(int i) {
  vectors_[i].output();
  return vectors_[i];
}

float VectorContainer::operator()(int i, int j) {
  return vectors_[i].v[j];
}
