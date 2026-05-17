#include "nucleotide_count.h"
#include <stdexcept>
namespace nucleotide_count {

std::map<char, int> count(const std::string& strand) {
    std::map<char, int> result{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (char c : strand) {
        if (result.find(c) == result.end()) {
            throw std::invalid_argument(std::string("Invalid nucleotide: " ) + c);
        }
        result[c]++;
    }

    return result;
}
    

}  // namespace nucleotide_count
