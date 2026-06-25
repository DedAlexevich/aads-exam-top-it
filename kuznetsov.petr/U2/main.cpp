#include <fstream>
#include <iostream>

#include "../common/darray.hpp"
#include "../common/person.hpp"
#include "meeting.hpp"

int main(int argc, char** argv)
{
  namespace kuz = kuznetsov;
  std::ifstream ifile;
  std::ifstream idata;
  std::string iPath, dataPath;
  std::istream* source = &std::cin;
  std::istream* dataSource = &std::cin;
  size_t countInp = 0, countData = 0;
  if (argc > 3) {
    std::cerr << "Too musn args\n";
    return 0;
  }

  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      std::string str = argv[i];
      if (str.find("in:") == 0) {
        std::string path = str.substr(3);
        iPath = path;
        countInp++;
      } else if (str.find("data:") == 0) {
        std::string path = str.substr(4);
        dataPath = path;
        countData++;
      } else {
        return 1;
      }
    }
  }

  if (countData != 1) {
    std::cerr << "Not data file\n";
    return 1;
  }
  idata.open(dataPath);
  if (!ifile) {
    std::cerr << "Cant open file\n";
    return 2;
  }

  kuz::darray< kuz::Person > persons;
  kuz::darray< kuz::Meeting > meets;
  if (countInp == 1) {
    ifile.open(iPath);
    if (!ifile) {
      std::cerr << "Cant open file\n";
      return 2;
    }
    source = &ifile;
    persons = kuz::readArray(*source, 0, 0);
  }

  meets = kuz::readArrayMeets(idata);






}
