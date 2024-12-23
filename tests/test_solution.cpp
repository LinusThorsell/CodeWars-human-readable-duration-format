#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(SolutionTest, DefaultCase) {
    EXPECT_EQ(format_duration(0), "now");
    EXPECT_EQ(format_duration(1), "1 second");
    EXPECT_EQ(format_duration(62), "1 minute and 2 seconds");
    EXPECT_EQ(format_duration(120), "2 minutes");
    EXPECT_EQ(format_duration(3662), "1 hour, 1 minute and 2 seconds");
}
