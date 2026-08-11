#include "bob.h"
#include <algorithm>
#include <string>

namespace bob {

std::string hey(const std::string& what) {
    size_t first = what.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return "Fine. Be that way!";
    }

    size_t last = what.find_last_not_of(" \t\n\r");
    bool isQuestion = (what[last] == '?');

    bool hasLetters = std::any_of(what.begin(), what.end(), ::isalpha);
    bool isShouting = hasLetters && std::all_of(what.begin(), what.end(), [](unsigned char c) {
        return !std::isalpha(c) || std::isupper(c);
    });

    if (isShouting && isQuestion) return "Calm down, I know what I'm doing!";
    if (isShouting) return "Whoa, chill out!";
    if (isQuestion) return "Sure.";
    return "Whatever.";
}

}  // namespace bob