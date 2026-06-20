// armstrong_numbers.cpp
#include "armstrong_numbers.h"
#include <cmath>
#include <string>

namespace armstrong_numbers {

bool is_armstrong_number(int number) {
    std::string digits = std::to_string(number);
    int n = digits.size();  // 位数
    int sum = 0;

    for (char c : digits) {
        int d = c - '0';  // 字符转数字
        sum += std::pow(d, n);
    }

    return sum == number;
}

}  // namespace armstrong_numbers