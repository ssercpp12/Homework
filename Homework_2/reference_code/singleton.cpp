// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include "singleton.h"

// static
Singleton Singleton::instance_;

// static
Singleton& Singleton::GetInstance() {
  return instance_;
}

void Singleton::SetValue(int value) {
  value_ = value;
}

int Singleton::GetValue() {
  return value_;
}
