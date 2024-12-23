## Coding challenge - CodeWars - Human readable duration format

Source of the challenge: https://www.codewars.com/kata/52742f58faf5485cae000b9a/train/cpp

### Summary of problem - Authored by ChatGPT

Write a function that transforms a non-negative integer of seconds into a human-readable duration. If the input is zero, return “now.” Otherwise, break down the total seconds into years (365 days), days, hours, minutes, and seconds. The result must be listed in descending order of significance and must include only those units that have non-zero values.

For example, 62 seconds translates to “1 minute and 2 seconds,” and 3662 seconds translates to “1 hour, 1 minute and 2 seconds.” Larger numbers work the same way. For instance, 31536000 seconds (which is 365 days) should become “1 year,” while 90000 seconds should become “1 day and 1 hour.”

Remember to use the plural forms of units when their values exceed one (e.g., “5 minutes,” “2 days”). Separate multiple components with “, ” (comma plus space), but use “ and ” before the last component. Also, ensure you express durations with the greatest possible units, so you would never display “61 seconds” when you can display “1 minute and 1 second.” If any particular unit has a value of zero, simply omit it from the final string.

### Basic testcases

There are many more testcases in the [tests](/tests/test_solution.cpp) file.

```c++
#include <gtest/gtest.h>
#include "../src/solution.h"

TEST(SolutionTest, DefaultCase) {
    EXPECT_EQ(format_duration(0), "now");
    EXPECT_EQ(format_duration(1), "1 second");
    EXPECT_EQ(format_duration(62), "1 minute and 2 seconds");
    EXPECT_EQ(format_duration(120), "2 minutes");
    EXPECT_EQ(format_duration(3662), "1 hour, 1 minute and 2 seconds");
}
```

### Solution

solution.h

```c++
#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>

std::string format_duration(int seconds);

#endif
```

solution.cpp

```c++
#include "solution.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

static constexpr int SECONDS_IN_YEAR = 31536000;
static constexpr int SECONDS_IN_DAY = 86400;
static constexpr int SECONDS_IN_HOUR = 3600;
static constexpr int SECONDS_IN_MINUTE = 60;

std::string format_plural(int amount, const std::string &label) {
    std::ostringstream oss;

    oss << amount << " " << label;
    if (amount != 1) {
        oss << "s";
    }

    return oss.str();
}

std::string vec_to_string(const std::vector<std::string> &parts) {
    if (parts.size() == 1) {
        return parts[0];
    }

    std::ostringstream oss;
    for (std::size_t i = 0; i < parts.size() - 1; i++) {
        oss << parts[i];
        if (i < parts.size() - 2) {
            oss << ", ";
        }
    }

    oss << " and " << parts.back();

    return oss.str();
}

std::string format_duration(int input_seconds) {
    if (input_seconds == 0) {
        return "now";
    }

    int years = input_seconds / SECONDS_IN_YEAR;
    int remaining_seconds = input_seconds % SECONDS_IN_YEAR;

    int days = remaining_seconds / SECONDS_IN_DAY;
    remaining_seconds = remaining_seconds % SECONDS_IN_DAY;

    int hours = remaining_seconds / SECONDS_IN_HOUR;
    remaining_seconds = remaining_seconds % SECONDS_IN_HOUR;

    int minutes = remaining_seconds / SECONDS_IN_MINUTE;
    int seconds = remaining_seconds % SECONDS_IN_MINUTE;

    std::vector<std::string> strings;
    if (years > 0) strings.push_back(format_plural(years, "year"));
    if (days > 0) strings.push_back(format_plural(days, "day"));
    if (hours > 0) strings.push_back(format_plural(hours, "hour"));
    if (minutes > 0) strings.push_back(format_plural(minutes, "minute"));
    if (seconds > 0) strings.push_back(format_plural(seconds, "second"));

    return vec_to_string(strings);
}
```
