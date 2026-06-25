#include "person.hpp"
#include "vector.hpp"
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

std::istream &dirko::input(std::istream &in, Vector< Person > &persons, size_t &ignored)
{

  size_t id = 0;
  while (in >> id) {
    if (!in) {
      in.clear();
      in.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      ++ignored;
    }
    for (size_t i = 0; i < persons.size; ++i) {
      if (persons.data[i].id == id) {
        in.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
        ++ignored;
        continue;
      }
    }
    std::string info;
    in >> std::ws;
    std::getline(in, info);
    if (info.empty()) {
      ++ignored;
    } else {
      add(persons, {id, info});
    }
  }
  return in;
}
std::ostream &dirko::output(std::ostream &out, Vector< Person > &persons)
{
  for (size_t i = 0; i < persons.size; ++i) {
    out << persons.data[i].id << ' ' << persons.data[i].info << '\n';
  }
  return out;
}
