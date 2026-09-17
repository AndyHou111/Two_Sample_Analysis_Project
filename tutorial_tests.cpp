#include "tutorial.hpp"
#include "unit_test_framework.hpp"

// We define a test case with the TEST(<test_name>) macro.
// <test_name> can be any valid C++ function name.
TEST(true_is_true) {
  ASSERT_TRUE(true);
}

TEST(numbers_are_equal) {
  ASSERT_EQUAL(42, 42);
}

TEST_MAIN() // No semicolon!