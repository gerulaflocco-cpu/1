#pragma once

#include <array>
#include <string>

namespace kindergarten_garden {

enum class Plants { grass, clover, radishes, violets };

std::array<Plants, 4> plants(std::string diagram, std::string student);

}  // namespace kindergarten_garden