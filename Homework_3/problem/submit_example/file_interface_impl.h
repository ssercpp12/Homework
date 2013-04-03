#ifndef  FILE_INTERFACE_IMPL_H_
#define  FILE_INTERFACE_IMPL_H_

#include "file_interface.h"

class FileInterfaceImpl : public FileInterface {
 public:
  FileInterfaceImpl(const std::string& filename);
  virtual ~FileInterfaceImpl();

  virtual const std::string& GetWordByPos(int pos) const;
  virtual const std::string& operator[](int pos) const;
  virtual bool GetNext();
  virtual const std::string& word() const;
  virtual bool SaveTo(const std::string& filename) const;
};

#endif  // FILE_INTERFACE_IMPL_H_
