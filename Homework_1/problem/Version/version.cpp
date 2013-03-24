#include "version.h"

Version::Version(const std::string& version_str) {
  // This is the construction function for class Version. Parse the string here.
  // For instance, if the |version_str| is "0.1.0", the |components_| shoudld
  // become [0, 1, 0, ......] and the |components_size_| should be 3; 
  // Another case: "25.0.1364.97", |components_| should be [25, 0, 1364, 97] and
  // |components_size_| should be 4;
  // A valid version should only contain numbers and '.'. What's more, it 
  // shoudld end with number. If the |version_str| contain other characters, it 
  // is invalid and what you need to do is just set the |components_size_| with
  // value 0. Here is come invalid case: "-1.0", "1.-1.0", "+1.0", ".", "2a.1".
}

bool Version::IsValid() const {
  // FIXME: depend on the |components_size_|. if |components_size_| == 0, return
  // false, otherwise return true.
  return false;
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
  return 0;
}
