#include "trinary.h"

namespace trinary {

int to_decimal(const std::string& s) {
    int result = 0;
    for (char c : s) {
        if (c < '0' || c > '2') return 0;
        result = result * 3 + (c - '0');
    }
    return result;
}

}  // namespace trinary
