// hexadecimal.cpp
#include "hexadecimal.h"

namespace hexadecimal {

int convert(const std::string& input) {
    int result = 0;

    for (char c : input) {
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';         // '7' → 7
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;   // 'a'→10, 'b'→11, ..., 'f'→15
        } else {
            return 0;                // 无效字符
        }
        result = result * 16 + digit;
    }

    return result;
}

}  // namespace hexadecimal