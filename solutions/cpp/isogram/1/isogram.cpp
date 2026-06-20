// isogram.cpp
#include "isogram.h"
#include <cctype>
#include <array>

namespace isogram {

bool is_isogram(const std::string& input) {
    std::array<bool, 26> seen{};  // 全部初始化为 false

    for (char c : input) {
        if (c == '-' || c == ' ') continue;  // 跳过连字符和空格
        int idx = std::tolower(c) - 'a';
        if (seen[idx]) return false;          // 重复了
        seen[idx] = true;
    }

    return true;
}

}  // namespace isogram