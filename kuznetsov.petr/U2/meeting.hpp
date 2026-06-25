#ifndef AADS_EXAM_TOP_IT_MEETING_HPP
#define AADS_EXAM_TOP_IT_MEETING_HPP
#include <cstddef>
#include <iosfwd>

namespace kuznetsov {

  struct Meeting {
    size_t id1, id2;
    size_t time;
  };

  Meeting readMeeting(std::istream& in, bool& success, darray< Person >& p);
  darray< Meeting > readArrayMeets(std::istream& in, darray< Person >& p);

}

#endif
