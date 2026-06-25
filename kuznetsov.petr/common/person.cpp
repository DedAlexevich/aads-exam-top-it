#include "person.hpp"
#include <iostream>

kuznetsov::Person kuznetsov::readPerson(std::istream& in, bool& success)
{
  size_t id;
  in >> id;
  if (!in) {
    success = false;
    in.clear();
    std::string skip;
    std::getline(in, skip);
    return {};
  }
  while (in.peek() == ' ' || in.peek() == '\t') {
    in.ignore();
  }
  std::string inf;
  std::getline(in, inf);
  if (inf.empty()) {
    success = false;
    return {};
  }
  success = true;
  return Person{id, inf};
}

bool kuznetsov::equalPersons(const Person& a, const Person& b)
{
  bool f = a.id == b.id;
  return f;
}

