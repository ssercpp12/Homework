#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef unsigned char uchar;

string CharToBitStr(uchar c) {
  string re;
  uchar mask = 0x01;
  for (int i = 0; i < 8; ++i) {
    re.insert(re.begin(), mask & c ? '1' : '0');
    mask <<= 1;
  }
  return re;
}

int main(int argc, char *argv[]) {
  ifstream infile;
  ofstream outfile;
  infile.open("file.in", ifstream::in);
  outfile.open("file.out");
  
  uchar ch = infile.get();
  while (infile.good()) {
    outfile << CharToBitStr(ch);
    if (ch == 'a') {
      cout << ch << CharToBitStr(ch) << endl;
    }
    ch = infile.get();
  }

  infile.close();
  return 0;
}
