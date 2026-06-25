#include "commands.hpp"
#include <cstddef>
#include <iostream>

void kuznetsov::detail::sort(darray< size_t >& arr)
{
  for (size_t i = 0; i < arr.size; ++i) {
    size_t min = i;
    for (size_t j = i + 1; j < arr.size; ++j) {
      if (arr.data[j] < arr.data[min]) {
        min = j;
      }
    }
    if (min != i) {
      std::swap(arr.data[min], arr.data[i]);
    }
  }
}

size_t kuznetsov::detail::findPersonIdx(darray< Person >& pers, size_t id)
{
  for (size_t i = 0; i < pers.size; ++i) {
    if (pers.data[i].id == id) {
      return i;
    }
  }
  return pers.cap;
}

void kuznetsov::anons(std::istream&, std::ostream& out, darray< Meeting >& mts, darray< Person >& pers)
{
  darray< size_t > ids = makeDarray< size_t >(8);
  for (size_t i = 0; i < pers.size; ++i) {
    if (pers.data[i].info == "") {
      pushBackDarray(ids, pers.data[i].id);
    }
  }
  detail::sort(ids);
  for (size_t i = 0; i < ids.size; ++i) {
    out << ids.data[i] << '\n';
  }
}

void kuznetsov::deanon(std::istream& in, std::ostream&, darray< Meeting >& mts, darray< Person >& prs)
{
  size_t anonId, id;
  in >> anonId >> id;
  if (in.fail()) {
    throw std::logic_error("Smth go bad");
  }
  if (prs.data[detail::findPersonIdx(prs, anonId)].info != "") {
    throw std::logic_error("Bad anon");
  }
  if (prs.data[detail::findPersonIdx(prs, id)].info == "") {
    throw std::logic_error("Bad id");
  }

  for (size_t i = 0; i < mts.size; ++i) {
    if (mts.data[i].id1 == anonId) {
      mts.data[i].id1 = id;
    }
    if (mts.data[i].id2 == anonId) {
      mts.data[i].id2 = id;
    }
  }
  size_t i = 0;
  while (i < mts.size) {
    if (mts.data[i].id1 == mts.data[i].id2) {
      removeDarray(mts, i);
      i -= 2;
    }
    i += 1;
  }
}

