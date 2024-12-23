#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(SolutionTest, DefaultCase) {
    EXPECT_EQ(format_duration(0), "now");
    EXPECT_EQ(format_duration(1), "1 second");
    EXPECT_EQ(format_duration(62), "1 minute and 2 seconds");
    EXPECT_EQ(format_duration(120), "2 minutes");
    EXPECT_EQ(format_duration(3662), "1 hour, 1 minute and 2 seconds");
}

TEST(SolutionTest, MinuteBoundaryCases) {
    EXPECT_EQ(format_duration(59), "59 seconds");
    EXPECT_EQ(format_duration(60), "1 minute");
    EXPECT_EQ(format_duration(61), "1 minute and 1 second");
}

TEST(SolutionTest, HourBoundaryCases) {
    EXPECT_EQ(format_duration(3599), "59 minutes and 59 seconds");
    EXPECT_EQ(format_duration(3600), "1 hour");
    EXPECT_EQ(format_duration(3601), "1 hour and 1 second");
}

TEST(SolutionTest, DayBoundaryCases) {
    EXPECT_EQ(format_duration(86399), "23 hours, 59 minutes and 59 seconds");
    EXPECT_EQ(format_duration(86400), "1 day");
    EXPECT_EQ(format_duration(86401), "1 day and 1 second");
}

TEST(SolutionTest, YearBoundaryCases) {
    EXPECT_EQ(format_duration(31535999), "364 days, 23 hours, 59 minutes and 59 seconds");
    EXPECT_EQ(format_duration(31536000), "1 year");
    EXPECT_EQ(format_duration(31536001), "1 year and 1 second");
}

TEST(SolutionTest, MultiYearCases) {
    EXPECT_EQ(format_duration(63072000), "2 years");
    EXPECT_EQ(format_duration(63072001), "2 years and 1 second");
}

TEST(SolutionTest, ExtraCases) {
    EXPECT_EQ(format_duration(63162001), "2 years, 1 day, 1 hour and 1 second");
    EXPECT_EQ(format_duration(3661), "1 hour, 1 minute and 1 second");
}

