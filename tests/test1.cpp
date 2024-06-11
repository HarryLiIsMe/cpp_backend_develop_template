#include "gtest/gtest.h"

TEST(TestCaseSuite1, test_case1) { ASSERT_TRUE(true) << "test case1 failed"; }

TEST(TestCaseSuite1, test_case2) { ASSERT_FALSE(true) << "test case2 failed"; }
