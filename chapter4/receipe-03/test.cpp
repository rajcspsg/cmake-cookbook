#include "sum_integers.hpp"
#include "gtest/gtest.h"

#include <vector>

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(example, sum_zero) {
  auto integers = {1, 2, 3,-3,-3};
  ASSERT_EQ(sum_integers(integers),0);
}
