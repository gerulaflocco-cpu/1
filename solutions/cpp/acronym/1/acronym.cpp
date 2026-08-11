#include "acronym.h"
#include <cctype>
#include <sstream>

namespace acronym {

std::string acronym(const std::string& phrase) {
    std::string result;
    bool newWord = true;

    for (char c : phrase) {
        if (c == ' ' || c == '-' || c == '_') {
            newWord = true;
        } else if (std::isalpha(c)) {
            if (newWord) {
                result += std::toupper(c);
                newWord = false;
            }
        }
        // apostrophes, commas, etc. are skipped without setting newWord
    }

    return result;
}

}  // namespace acronym