#include "sum_integers.hpp"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Sum of integers for a short vector", "[short]") {
  auto integers = {1, 2,3,4, 5};
  REQUIRE(sum_integers(integers) == 15);
}

TEST_CASE("sum of integers for long vector", "[long]") {

  std::vector<int> integers;

  for(auto i = 1 ; i < 1001; i++) {
	integers.push_back(i);
  }
  REQUIRE(sum_integers(integers) == 500500);
}

