
#include "anagram.h"

#include <algorithm>
#include <cctype>

namespace anagram {

namespace {

std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                    [](unsigned char c) { return std::tolower(c); });
    return s;
}

std::string sorted_lower(const std::string& s) {
    std::string result = to_lower(s);
    std::sort(result.begin(), result.end());
    return result;
}

}  // namespace

anagram::anagram(std::string subject) : subject_(std::move(subject)) {}

std::vector<std::string> anagram::matches(
    std::vector<std::string> const& candidates) const {
    std::vector<std::string> result;
    const std::string subject_lower = to_lower(subject_);
    const std::string subject_sorted = sorted_lower(subject_);

    for (const auto& candidate : candidates) {
        if (to_lower(candidate) == subject_lower) {
            continue;  // 单词本身不是它的字谜
        }
        if (sorted_lower(candidate) == subject_sorted) {
            result.push_back(candidate);
        }
    }

    return result;
}

}  // namespace anagram