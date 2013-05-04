#include <iostream>
#include "file_interface_impl.h"

int main(int argc, char *argv[]) {
  FileInterfaceImpl f("file.out");
  int counter = 0;
  while (f.GetNext()) {
    std::cout << counter++ << " "<< f.word() << std::endl;
  }

  f.SaveTo("my_file.txt"); // This will save the words to file |my_file.txt|.
  return 0;
}

