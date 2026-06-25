#ifndef AADS_EXAM_TOP_IT_MEETING_HPP
#define AADS_EXAM_TOP_IT_MEETING_HPP
#include <cstddef>
#include <iosfwd>

namespace kuznetsov {

  struct Meeting {
    size_t id1, id2;
    size_t time;
  };

  Meeting readMeeting(std::istream& in, bool& success);
  darray< Meeting > readArrayMeets(std::istream& in, size_t& cSucces, size_t& cFail);

}

#endif
