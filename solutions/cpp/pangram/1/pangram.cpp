#include "pangram.h"
#include <cctype>

namespace pangram {

bool is_pangram(const std::string& sentence) {
    bool seen[26] = {};
    for (char c : sentence) {
        if (std::isalpha(c))
            seen[std::tolower(c) - 'a'] = true;
    }
    for (bool b : seen)
        if (!b) return false;
    return true;
}

}  // namespace pangram
