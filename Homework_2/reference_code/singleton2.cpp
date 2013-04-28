// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include "singleton2.h"

#include <cstddef>

// static
Singleton* Singleton::instance_ = NULL;

// static
Singleton& Singleton::GetInstance() {
  if (instance_ == NULL)
    instance_ = new Singleton();

  return *instance_;
}

// static
bool Singleton::DeleteInstance() {
  if (instance_ == NULL)
    return false;
  delete instance_;
  instance_ = NULL;
  return true;
}

void Singleton::SetValue(int value) {
  value_ = value;
}

int Singleton::GetValue() {
  return value_;
}
