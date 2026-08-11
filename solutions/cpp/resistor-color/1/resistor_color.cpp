#include "resistor_color.h"
#include <unordered_map>
#include <vector>

namespace resistor_color {

    int color_code(const std::string& color) {
        static const std::unordered_map<std::string, int> color_to_code = {
            {"black", 0},
            {"brown", 1},
            {"red", 2},
            {"orange", 3},
            {"yellow", 4},
            {"green", 5},
            {"blue", 6},
            {"violet", 7},
            {"grey", 8},
            {"white", 9}
        };
        
        auto it = color_to_code.find(color);
        if (it != color_to_code.end()) {
            return it->second;
        }
        return -1; // or throw, but tests expect valid inputs
    }

    std::vector<std::string> colors() {
        return {"black", "brown", "red", "orange",
                "yellow", "green", "blue", "violet",
                "grey", "white"};
    }

} // namespace resistor_color