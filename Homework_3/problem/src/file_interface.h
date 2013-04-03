#ifndef  FILE_INTERFACE_H_
#define  FILE_INTERFACE_H_

#include <vector>
#include <string>

// FileInterface is a simple file io interface, it is a abstract class. Take its
// subclass FileInterfaceImpl for example. 
// Example:
//   FileInterfaceImpl f("file.in");
//   int counter = 0;
//   while (f.GetNext()) {
//     std::cout << counter << " "<< f.word() << std::endl;
//   }
//   std::cout << f.GetWordByPos(0) << std::endl;
//
//The |file.in| file
//   "011001010111100001100001011011010111000001101100011001010010000001101111011011100110010100001010"
//
//Output
//    0 example
//    1 one
//    example
//
class FileInterface {
 public:
  FileInterface() : current_word_pos_(-1) {}
  virtual ~FileInterface() {}
  
  // Return the word by the specified pos. If the pos is invalid, return empty
  // string.
  virtual const std::string& GetWordByPos(int pos) const = 0;
  virtual const std::string& operator[](int pos) const = 0;

  // Call this method to advance the word to the next word.  This returns false
  // if the file content is end.
  virtual bool GetNext() = 0;

  // Return the current word.
  virtual const std::string& word() const = 0;

  // Save the transformed content to the file.
  virtual bool SaveTo(const std::string& filename) const = 0;

 protected:
  std::vector<std::string> words_;
  int current_word_pos_;
};

#endif  // FILE_INTERFACE_H_
