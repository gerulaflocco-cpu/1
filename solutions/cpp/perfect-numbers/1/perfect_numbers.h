// perfect_numbers.h
#pragma once
#include <stdexcept>

namespace perfect_numbers {

enum class classification {
    perfect,
    abundant,
    deficient
};

classification classify(int n);

} // namespace perfect_numbers