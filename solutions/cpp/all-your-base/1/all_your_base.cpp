// all_your_base.cpp
#include "all_your_base.h"
#include <algorithm>
namespace all_your_base {

std::vector<unsigned int> convert(unsigned int from_base,
                                  const std::vector<unsigned int>& digits,
                                  unsigned int to_base) {
    // 1. 验证输入
    if (from_base < 2) throw std::invalid_argument("from_base 必须 >= 2");
    if (to_base < 2)   throw std::invalid_argument("to_base 必须 >= 2");

    for (unsigned int d : digits) {
        if (d >= from_base) throw std::invalid_argument("数字超出输入进制范围");
    }

    // 2. 输入进制 → 十进制
    unsigned int value = 0;
    for (unsigned int d : digits) {
        value = value * from_base + d;
    }

    // 3. 处理 value == 0 的情况（空列表或全零）
    if (value == 0) return {};

    // 4. 十进制 → 输出进制
    std::vector<unsigned int> result;
    while (value > 0) {
        result.push_back(value % to_base); // 取余数（低位在前）
        value /= to_base;
    }

    // 5. 反转（低位 → 高位）
    std::reverse(result.begin(), result.end());

    return result;
}

} // namespace all_your_base