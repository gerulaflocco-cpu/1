#include "isbn_verifier.h"

namespace isbn_verifier {

bool is_valid(const std::string& isbn) {
    // Strip dashes
    std::string digits;
    for (char c : isbn) {
        if (c != '-')
            digits += c;
    }

    // Must be exactly 10 characters
    if (digits.size() != 10)
        return false;

    // Validate characters and compute checksum
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        int value;
        if (i == 9 && digits[i] == 'X') {
            value = 10;
        } else if (std::isdigit(digits[i])) {
            value = digits[i] - '0';
        } else {
            return false;  // invalid character
        }
        sum += value * (10 - i);
    }

    return sum % 11 == 0;
}

} // namespace isbn_verifier