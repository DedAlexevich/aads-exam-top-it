#include <iostream>
#include <cstddef>
#include <fstream>
#include "person.hpp"

namespace kuznetsov {
  Person readPerson(std::istream& in);


}

int main(int argc, char** argv)
{
  std::ifstream ifile;
  std::ofstream ofile;
  std::istream* source = &std::cin;
  std::ostream* output = &std::cout;
  size_t countInp = 0, countOut = 0;
  if (argc > 3) {
    return 1;
  }

  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      std::string str = argv[i];
      if (str.find("in:") == 0) {
        std::string path = str.substr(3);
        ifile.open(path);
        if (!ifile) {
          std::cerr << "Cant open file\n";
          return 1;
        }
        source = &ifile;
        countInp++;
      } else if (str.find("out:") == 0) {
        std::string path = str.substr(4);
        ofile.open(path);
        if (!ofile) {
          std::cerr << "Cant open file\n";
          return 1;
        }
        output = &ofile;
        countOut++;
      }
    }
  }

  if (countInp > 1 || countOut > 1) {
    return 1;
  }

}

kuznetsov::Person kuznetsov::readPerson(std::istream& in)
{
  size_t id;
  std::string inf;
  in >> id;
  char c;
  while (in.peek() == ' ') {
    in.get(c);
  }
  if (!in || c == '\n') {
    in.setstate(std::ios::failbit);
    return {};
  }
  in >> inf;
  return Person{id, inf};
}
