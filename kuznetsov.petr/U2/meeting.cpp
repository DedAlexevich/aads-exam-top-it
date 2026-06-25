#include "meeting.hpp"
#include <iostream>

kuznetsov::Meeting kuznetsov::readMeeting(std::istream& in, bool& success)
{
  size_t id1, id2, time;
  in >> id1 >> id2 >> time;
  return Meeting{ id1, id2, time };
}

kuznetsov::darray< kuznetsov::Meeting > kuznetsov::readArrayMeets(std::istream& in)
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


