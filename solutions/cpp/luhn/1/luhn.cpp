#include "luhn.h"
#include <algorithm>

namespace luhn {

bool valid(const std::string& input) {
    // 第一步：去掉所有空格
    std::string digits;
    for (char c : input) {
        if (c == ' ') continue;
        if (c < '0' || c > '9') return false;  // 非数字字符，直接无效
        digits += c;
    }

    // 第二步：长度必须大于1
    if (digits.size() <= 1) return false;

    // 第三步：从右往左，每隔一位乘以2
    int sum = 0;
    int size = digits.size();
    for (int i = 0; i < size; ++i) {
        int digit = digits[size - 1 - i] - '0';  // 从右往左取数字

        if (i % 2 == 1) {       // 第2、4、6...位（从右数）
            digit *= 2;
            if (digit > 9) digit -= 9;
        }

        sum += digit;
    }

    // 第四步：能被10整除则有效
    return sum % 10 == 0;
}

}  // namespace luhn