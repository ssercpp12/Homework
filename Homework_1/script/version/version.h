#ifndef VERSION_H_
#define VERSION_H_

#include <string>
#include <cstring>

class Version {
 public:
  explicit Version(const std::string& version_str);
 
  // Returns true if the object contains a valid version number.
  bool IsValid() const;

  // Returns -1, 0, 1 for <, ==, >.
  int CompareTo(const Version& other) const;

 private:
  int components_[10]; 
  int components_size_;
};

#endif
