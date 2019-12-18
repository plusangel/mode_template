#include "include/mode.h"
#include <iostream>
#include <stdexcept>

int main() {
  int v[] = {1, 1, 1, 1, 1, 1, 1, 5, 5, 3, 8, 1, 1};

  size_t length{sizeof(v) / sizeof(*v)};

  float res;
  res = mode(v, length);

  for (int i{}; i < length; ++i)
    std::cout << v[i] << " ";
  std::cout << std::endl;

  if (res)
    std::cout << "Mode: " << res << std::endl;
  else
    std::cout << "Error or multiple modes" << std::endl;

  return 0;
}
