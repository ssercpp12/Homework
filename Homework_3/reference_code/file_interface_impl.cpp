// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include "file_interface_impl.h"

#include <cmath>
#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

typedef unsigned char uchar;

char BitStrToChar(char str[]) {
  char c = 0;
  for (int i = 0; i < 8; i++) {
    c += (str[i] - '0') * pow(2, 7 - i);
  }

  return c;
}

FileInterfaceImpl::FileInterfaceImpl(const std::string& filename) {
  ifstream infile(filename.c_str(), ifstream::in);

  int counter = 0;
  string word;
  while (infile.good()) {
    char buffer[8];
    infile.read(buffer, 8);
    char c = BitStrToChar(buffer);
    if (c == ' ' || c == '\n') {
      words_.push_back(word);
      word.clear();
      if (c == '\n')
        break;
    } else {
      word.push_back(c);
    }
  }

  infile.close();
}

FileInterfaceImpl::~FileInterfaceImpl() {
}

const std::string& FileInterfaceImpl::GetWordByPos(int pos) const {
  if (pos < 0 || pos >= words_.size())
    return emptyStr_;
  return words_[pos];
}

const std::string& FileInterfaceImpl::operator[](int pos) const {
  return GetWordByPos(pos);
}

bool FileInterfaceImpl::GetNext() {
  current_word_pos_++;
  return current_word_pos_ < words_.size();
}

const std::string& FileInterfaceImpl::word() const {
  return GetWordByPos(current_word_pos_);
}

bool FileInterfaceImpl::SaveTo(const std::string& filename) const {
  ofstream outfile(filename.c_str(), ofstream::out);
  if ((outfile.rdstate() & ifstream::failbit) != 0)
    return false;

  int i;
  for (i = 0; i < words_.size() - 1; ++i) {
    outfile << words_[i] << " ";
  }
  outfile << words_[i] << "\n";

  outfile.close();
  return true;
}

