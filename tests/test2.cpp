#include "gtest/gtest.h"

TEST(TestCaseSuite2, test_case3) { ASSERT_TRUE(true) << "test case1 failed"; }

TEST(TestCaseSuite2, test_case4) { ASSERT_FALSE(true) << "test case2 failed"; }
