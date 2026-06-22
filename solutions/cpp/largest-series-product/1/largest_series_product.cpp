#include "largest_series_product.h"
#include <stdexcept>
#include <algorithm>

namespace largest_series_product {

long long largest_product(const std::string& digits, int span) {
    // Validate inputs
    if (span < 0)
        throw std::domain_error("span must not be negative");
    if (span > static_cast<int>(digits.size()))
        throw std::domain_error("span must be smaller than string length");
    for (char c : digits)
        if (!std::isdigit(c))
            throw std::domain_error("input must only contain digits");

    // span == 0 edge case: empty product is 1 by convention
    if (span == 0) return 1;

    long long max_product = 0;

    for (int i = 0; i <= static_cast<int>(digits.size()) - span; ++i) {
        long long product = 1;
        for (int j = i; j < i + span; ++j)
            product *= (digits[j] - '0');
        max_product = std::max(max_product, product);
    }

    return max_product;
}

} // namespace largest_series_product