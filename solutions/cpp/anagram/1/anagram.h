#pragma once
#include <string>
#include <vector>

namespace anagram {

class anagram {
    public:
    explicit anagram(std::string subject);
    std::vector<std::string> matches (
    std::vector<std::string> const& candidates) const;

    private:
    std::string subject_;
};

}  // namespace anagram
