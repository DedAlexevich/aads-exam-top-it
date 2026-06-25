#include "meeting.hpp"
#include <iostream>

kuznetsov::Meeting kuznetsov::readMeeting(std::istream& in, bool& success, darray< Person >& p)
{
  size_t id1, id2, time;
  in >> id1 >> id2 >> time;
  if (!containsDarray(p, Person{id1, ""}, equalPersons)) {
    pushBackDarray(p, Person{id1, ""});
  }
  if (!containsDarray(p, Person{id2, ""}, equalPersons)) {
    pushBackDarray(p, Person{id2, ""});
  }
  return Meeting{ id1, id2, time };
}

kuznetsov::darray< kuznetsov::Meeting > kuznetsov::readArrayMeets(std::istream& in, darray< Person >& p)
{
  darray< Meeting > meets = makeDarray< Meeting >(8);
  in >> std::ws;
  while (!in.eof()) {
    bool s = false;
    Meeting p = readMeeting(in, s);
    if (in.fail()) {
      in.clear();
      std::streamsize max = std::numeric_limits< std::streamsize >::max();
      in.ignore(max, '\n');
    } else {
      pushBackDarray(meets, p);
    }
  }
  return meets;
}


