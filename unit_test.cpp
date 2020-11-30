#include "gtest/gtest.h"

#include "iterator_test.hpp"
#include "base.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

