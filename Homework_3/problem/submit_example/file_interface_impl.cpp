#include "file_interface_impl.h"

FileInterfaceImpl::FileInterfaceImpl(const std::string& filename) {
}

FileInterfaceImpl::~FileInterfaceImpl() {
}

const std::string& FileInterfaceImpl::GetWordByPos(int pos) const {
  return words_[pos];
}

const std::string& FileInterfaceImpl::operator[](int pos) const {
  return words_[pos];
}

bool FileInterfaceImpl::GetNext() {
  return false;
}

const std::string& FileInterfaceImpl::word() const {
  return words_[current_word_pos_];
}

bool FileInterfaceImpl::SaveTo(const std::string& filename) const {
  return false;
}

