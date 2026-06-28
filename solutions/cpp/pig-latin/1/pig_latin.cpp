#include "pig_latin.h"

#include <cctype>
#include <sstream>
#include <string>

namespace pig_latin {

bool is_vowel(char c) {
    c = std::tolower(static_cast<unsigned char>(c));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::string translate_word(const std::string& word) {
    if (word.empty()) return "";

    // Rule 1
    if (is_vowel(word[0]) || 
        (word.size() >= 2 && word.substr(0, 2) == "xr") ||
        (word.size() >= 2 && word.substr(0, 2) == "yt")) {
        return word + "ay";
    }

    // Rule 3: ...qu
    size_t qu_pos = word.find("qu");
    if (qu_pos != std::string::npos) {
        bool all_consonants_before = true;
        for (size_t i = 0; i < qu_pos; ++i) {
            if (is_vowel(word[i])) {
                all_consonants_before = false;
                break;
            }
        }
        if (all_consonants_before) {
            std::string move = word.substr(0, qu_pos + 2);
            std::string rest = word.substr(qu_pos + 2);
            return rest + move + "ay";
        }
    }

    // Rule 4: ...y (preceded by consonants)
    size_t y_pos = word.find('y');
    if (y_pos != std::string::npos && y_pos > 0) {
        bool all_consonants_before = true;
        for (size_t i = 0; i < y_pos; ++i) {
            if (is_vowel(word[i])) {
                all_consonants_before = false;
                break;
            }
        }
        if (all_consonants_before) {
            std::string move = word.substr(0, y_pos);
            std::string rest = word.substr(y_pos);
            return rest + move + "ay";
        }
    }

    // Rule 2: leading consonant cluster
    size_t first_vowel_pos = 0;
    while (first_vowel_pos < word.size() && !is_vowel(word[first_vowel_pos])) {
        ++first_vowel_pos;
    }
    if (first_vowel_pos > 0 && first_vowel_pos < word.size()) {
        std::string move = word.substr(0, first_vowel_pos);
        std::string rest = word.substr(first_vowel_pos);
        return rest + move + "ay";
    }

    // Fallback (vowel start already handled)
    return word + "ay";
}

std::string translate(const std::string& phrase) {
    std::istringstream iss(phrase);
    std::ostringstream oss;
    std::string word;
    bool first_word = true;
    while (iss >> word) {
        if (!first_word) {
            oss << " ";
        }
        oss << translate_word(word);
        first_word = false;
    }
    return oss.str();
}

}  // namespace pig_latin