#include "version.h"

#include <vector>

namespace util {

// Splits |str| into a vector of strings delimited by |s|, placing the results
// in |r|. If several instances of |s| are contiguous, or if |str| begins with
// or ends with |s|, then an empty string is inserted.
static void SplitString(const std::string& str,
                        char s,
                        std::vector<std::string>* r) {
  r->clear();
  int last = 0;
  int c = str.size();

  for (int i = 0; i <= c; ++i) {
    if (i == c || str[i] == s) {
      std::string tmp(str, last, i - last);
      r->push_back(tmp);
      last = i + 1;
    }
  }
}

static bool StringToInt(const std::string& input, int *output) {
  if (input.size() == 0)
    return false;

  *output = 0;
  int base = 1;
  for (int i = input.size() - 1; i >= 0; i--) {
    if (input[i] < '0' || input[i] > '9')
      return false;
    *output += base * (input[i] - '0'); 
    base *= 10;
  }

  return true;
}

} // namespace util

Version::Version(const std::string& version_str) : components_size_(0) {
  // This is the construction function for class Version. Parse the string here.
  // For instance, if the |version_str| is "0.1.0", the |components_| shoudld
  // become [0, 1, 0, ......] and the |components_size_| should be 3; 
  // Another case: "25.0.1364.97", |components_| should be [25, 0, 1364, 97] and
  // |components_size_| should be 4;
  // A valid version should only contain numbers and '.'. What's more, it 
  // shoudld end with number. If the |version_str| contain other characters, it 
  // is invalid and what you need to do is just set the |components_size_| with
  // value 0. Here is come invalid case: "-1.0", "1.-1.0", "+1.0", ".", "2a.1".
  std::vector<std::string> numbers; 
  util::SplitString(version_str, '.', &numbers);
  if (numbers.empty() || numbers.size() > 10) {
    components_size_ = 0;
    return;
  }
  
  for (int i = 0; i < numbers.size(); ++i) {
    int num;
    if (!util::StringToInt(numbers[i], &num)) {
      components_size_ = 0;
      return;
    }

    components_[i] = num;
  }

  components_size_ = numbers.size();
}

bool Version::IsValid() const {
  // FIXME: depend on the |components_size_|. if |components_size_| == 0, return
  // false, otherwise return true.
  return components_size_ != 0;
}

int Version::CompareTo(const Version& other) const {
  // FIXME: return -1, 0, 1 for <, ==, >. If anyone of these version is invalid,
  // return -2.
  // For example: "1.0.0" < "2.0"(other), return -1
  //              "0.2.0" < "1.0.0"(other), return -1
  //              "1.0.0" == "1.0"(other), return 0
  //              "25.0.1364" > "25.0.1224"(other), return 1
  //              "1.0" == "1.0"(other), return 0
  //              "1.0" > "0.0", return 1
  //              "1.0" < "2.0", return -1
  //              "1.0" < "1.1", return -1
  //              "1.1" > "1.0", return  1
  //              "1.0" < "1.0.1", return -1
  //              "1.1" > "1.0.1", return 1
  //              "1.0.3" < "1.0.20", return -1
  if (!IsValid() || !other.IsValid())
    return -2;

  int count = std::min(components_size_, other.components_size_);
  for (int i = 0; i < count; ++i) {
    if (components_[i] > other.components_[i])
      return 1;
    if (components_[i] < other.components_[i])
      return -1;
  }

  if (components_size_ > other.components_size_) {
    for (int i = count; i < components_size_; ++i) {
      if (components_[i] > 0)
        return 1;
    }
  } else if (components_size_ < other.components_size_) {
    for (int i = count; i < other.components_size_; ++i) {
      if (other.components_[i] > 0)
        return -1;
    }
  }

  return 0;
}
