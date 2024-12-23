#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(SolutionTest, DefaultCase) {
    EXPECT_EQ(solution(10), 23);
}
