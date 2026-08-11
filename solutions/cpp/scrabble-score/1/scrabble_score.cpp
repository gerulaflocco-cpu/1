// scrabble_score.cpp
#include "scrabble_score.h"
#include <cctype> // toupper

namespace scrabble_score {

int score(const std::string& word) {
    // 按字母顺序 A~Z 对应的分值
    const int letter_scores[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,  // A B C D E F G H I J K L M
        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10  // N O P Q R S T U V W X Y Z
    };

    int total = 0;
    for (char c : word) {
        total += letter_scores[std::toupper(c) - 'A'];
    }
    return total;
}

} // namespace scrabble_score