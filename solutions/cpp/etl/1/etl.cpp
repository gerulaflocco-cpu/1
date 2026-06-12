#include "etl.h"
#include <cctype>

namespace etl {

    std::map<char, int> transform(const std::map<int, std::vector<char>>& old) {
        std::map<char, int> result;
        for (const auto& [score, letters] : old) {
            for (char letter : letters) {
                result[static_cast<char>(std::tolower(letter))] = score;
            }
        }
        return result;
    }

}  // namespace etl
