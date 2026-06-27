#include "resistor_color_duo.h"
#include <unordered_map>

namespace resistor_color_duo {

    // 颜色到数字的映射（复用上一个练习的颜色表）
    int color_code(const std::string& color) {
        static const std::unordered_map<std::string, int> color_to_code = {
            {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
            {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
            {"grey", 8}, {"white", 9}
        };

        auto it = color_to_code.find(color);
        return (it != color_to_code.end()) ? it->second : 0;
    }

    int value(const std::vector<std::string>& colors) {
        if (colors.empty()) {
            return 0;
        }

        int first = color_code(colors[0]);
        int second = (colors.size() >= 2) ? color_code(colors[1]) : 0;

        return first * 10 + second;
    }

} // namespace resistor_color_duo