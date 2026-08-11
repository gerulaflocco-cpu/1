#include "word_count.h"
#include <algorithm>
#include <cctype>
namespace word_count {

std::map<std::string, int> words(const std::string& input) {
    std::map<std::string, int> counts;    
    std::string word;

    auto flush = [&]() {
        if (!word.empty()) {
            while (!word.empty() && word.front() == '\'') word.erase(word.begin());
            while (!word.empty() && word.back() == '\'') word.pop_back();
         if (!word.empty()) counts[word]++;
            word.clear();
        }
    };

for (char c : input) {
    if (std::isalnum(static_cast<unsigned char>(c))) {
        word += std::tolower((static_cast<unsigned char>(c)));
    } else if (c == '\'' && !word.empty()) {
        word += c;
    } else {
        flush();
    }
}
    flush();
    return counts;
}
    
}  // namespace word_count
