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
