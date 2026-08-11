// all_your_base.h
#pragma once
#include <vector>
#include <stdexcept>

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int from_base,
                                  const std::vector<unsigned int>& digits,
                                  unsigned int to_base);

} // namespace all_your_base