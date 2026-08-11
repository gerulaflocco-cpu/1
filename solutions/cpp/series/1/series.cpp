#include "series.h"
#include <stdexcept>

namespace series {

std::vector<std::string> slice(const std::string& s, int n) {
    if ( n <=0 || s.empty() || n > static_cast<int>(s.size()))
        throw std::domain_error("invalid slice length");

    std::vector<std::string> result;
    for (int i = 0; i <= static_cast<int>(s.size()) - n; ++i)
        result.push_back(s.substr(i, n));

    return result;
}

}
