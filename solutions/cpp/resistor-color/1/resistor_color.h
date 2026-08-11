#pragma once

#include <string>
#include <vector>

namespace resistor_color {

    // Returns the numeric code for a given color band
    int color_code(const std::string& color);

    // Returns all colors in order from 0 to 9
    std::vector<std::string> colors();

} // namespace resistor_color