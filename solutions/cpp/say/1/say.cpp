#include "say.h"

namespace say {

namespace {
    const std::string ones[] = {
    "", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
    };

    const std::string tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
    };

std::string say_below_1000( int n) {
    if (n == 0) return "";

    std::string result;

    if (n >= 100) {
        result += ones[n/100] + " hundred";
        n %= 100;
        
    }

    if (n >= 20) {
        if (!result.empty()) result += " "; 
        result += tens[n / 10];
        if (n % 10 > 0)
            result += "-" + ones[n % 10];
    } else if (n > 0) {
        if (!result.empty()) result += " "; 
        result += ones[n];
    }

    return result;
}
}
    std::string in_english(long long number) {
        if (number < 0 || number > 999'999'999'999LL)
            throw std::domain_error("number out of range");

        if (number == 0) return "zero";

        std::string result;

        struct Group {
        long long divisor;
        std::string name;
        };

    const Group groups[] = {
        {1'000'000'000LL, "billion"},
        {1'000'000LL, "million"},
        {1'000LL, "thousand"},
        {1LL, ""},
    };

    for (const auto& g: groups) {
        long long chunk = number / g.divisor;
        if (chunk > 0) {
            if (!result.empty()) result += " ";
            result += say_below_1000(static_cast<int>(chunk));
            if(!g.name.empty())
                result += " " + g.name;
        }
        number %= g.divisor;
    }

    return result;
    }
    

}  // namespace say
