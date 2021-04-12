#include "sum_integers.hpp"
#include <string>
#include <iostream>
#include <vector>

int main (int argc, char *argv[]) {
  
  std::vector<int> integers;
  std::cout << "argc" << argc << std::endl;
  for (auto i = 1; i < argc; i++) {
	integers.push_back(std::stoi(argv[i]));
  }
  auto sum = sum_integers(integers);
  std::cout << sum << std::endl;
}
