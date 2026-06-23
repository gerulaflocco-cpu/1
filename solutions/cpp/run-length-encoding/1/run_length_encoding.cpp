#include "run_length_encoding.h"
#include <string>
#include <cctype>

namespace run_length_encoding {

std::string encode(const std::string& input) {
    std::string result;
    int n = input.size();
    if (n == 0) return "";

    int count = 1;

    for (int i = 1; i <= n; ++i) {
        if (i < n && input[i] == input[i - 1]) {
            ++count;
        } else {
            if (count > 1) {
                result += std::to_string(count);
            }
            result += input[i - 1];
            count = 1;
        }
    }

    return result;
}

std::string decode(const std::string& input) {
    std::string result;
    int n = input.size();
    int i = 0;

    while (i < n) {
        if (std::isdigit(input[i])) {
            int count = 0;

            // 处理多位数字
            while (i < n && std::isdigit(input[i])) {
                count = count * 10 + (input[i] - '0');
                ++i;
            }

            // 之后一定是字符
            if (i < n) {
                result.append(count, input[i]);
                ++i;
            }
        } else {
            // 没有数字 => 默认 1
            result += input[i];
            ++i;
        }
    }

    return result;
}

} // namespace run_length_encoding