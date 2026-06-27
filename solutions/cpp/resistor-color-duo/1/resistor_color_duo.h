#pragma once

#include <string>
#include <vector>

namespace resistor_color_duo {

    // Returns the resistance value as an integer from the first two color bands
    int value(const std::vector<std::string>& colors);

} // namespace resistor_color_duo