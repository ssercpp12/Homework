// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#ifndef  FILE_INTERFACE_IMPL_H_
#define  FILE_INTERFACE_IMPL_H_

#include "file_interface.h"

#include <string>

class FileInterfaceImpl : public FileInterface {
 public:
  FileInterfaceImpl(const std::string& filename);
  virtual ~FileInterfaceImpl();

  virtual const std::string& GetWordByPos(int pos) const;
  virtual const std::string& operator[](int pos) const;
  virtual bool GetNext();
  virtual const std::string& word() const;
  virtual bool SaveTo(const std::string& filename) const;

 private:
  // Empty string for return value, in order to eliminate the warning caused by
  // |return "";|. I(zhchbin) just make a little misstake when writing the
  // requirement.
  std::string emptyStr_;
};

#endif  // FILE_INTERFACE_IMPL_H_
