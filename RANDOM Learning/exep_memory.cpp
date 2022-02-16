#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <num.hpp>

#define SIZE 3
auto range_ptr()   {
  num* res = new num[SIZE];
  int i    = 0;
  auto it  = res;
  auto end = res + SIZE;
  while(it != end) *(it++) = i++; return res;
}

auto range_vec()   {
  std::vector<num> res(SIZE);
  int i    = 0;
  auto it  = res.begin();
  auto end = res.end();
  while(it != end) *(it++) = i++;
  return res;
}

auto range_smart() {
  auto res = std::make_unique<std::array<num, SIZE>>();
  int i    = 0;
  auto it  = res->begin();
  auto end = res->end();
  while(it != end) *(it++) = i++;
  return res;
}

void f() {throw std::string("ouch !");}

void g() {
  fun_scope;
  auto ptr   = range_ptr();
  auto vec   = range_vec();
  auto smart = range_smart();
  ___;
  for(int i = 0; i < SIZE; ++i) {
    if(i > 0) f();
    std::cout << scope_indent << '(' << ptr[i] << ", " << vec[i] << ", " << (*smart)[i] << ')' << std::endl;
  }

  // Unreached code... ptr is a memory leak.
  delete [] ptr; 
}

int main(int argc, char* argv[]) {
  fun_scope;
  for(int i = 0; i < 2; ++i)
    try {g();}
    catch(...) {/* "Do nothing" handler. */}

  return 0;
}