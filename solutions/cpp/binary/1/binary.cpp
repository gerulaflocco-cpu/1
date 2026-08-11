// binary.cpp
#include "binary.h"

namespace binary {

int convert(const std::string& input) {
    int result = 0;

    for (char c : input) {
        if (c != '0' && c != '1') return 0;  // 无效字符
        result = result * 2 + (c - '0');
    }

    return result;
}

}  // namespace binary