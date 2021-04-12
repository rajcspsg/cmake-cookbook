#include <cstdlib>
#include "sum_integers.hpp"
#include <vector>

int sum_integers(const std::vector<int> integers) {
  int total = 0;
  for (auto i : integers) {
	total += i;
  }
  return total;
}
