#include "gtest/gtest.h"

TEST(TestCaseSuite2, test_case1) { ASSERT_TRUE(true) << "test case1 failed"; }

TEST(TestCaseSuite2, test_case2) { ASSERT_FALSE(true) << "test case2 failed"; }
