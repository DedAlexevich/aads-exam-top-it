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

void kuznetsov::anons(std::istream&, std::ostream& out, darray< Meeting >& mts, darray< Person >& pers)
{
  darray< size_t > ids = makeDarray(8);
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

