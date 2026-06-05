#include "food_chain.h"
#include <sstream>
namespace food_chain {

struct Animal {
    std::string name;
    std::string comment;
};

static const Animal animals[] = {
     {"fly",    ""},
    {"spider", "It wriggled and jiggled and tickled inside her."},
    {"bird",   "How absurd to swallow a bird!"},
    {"cat",    "Imagine that, to swallow a cat!"},
    {"dog",    "What a hog, to swallow a dog!"},
    {"goat",   "Just opened her throat and swallowed a goat!"},
    {"cow",    "I don't know how she swallowed a cow!"},
    {"horse",  ""},
};

    std::string verse(int v) {
    int i = v - 1;
    std::ostringstream out;

    out<< "I know an old lady who swallowed a " << animals[i].name << ".\n";

    if (i == 7) {
        out << "She's dead, of course!\n";
        return out.str();
    }

    if (!animals[i].comment.empty()) {
        out << animals[i].comment << "\n";
    }
    
    for (int j = i; j >= 1; --j) {
        out << "She swallowed the " << animals[j].name << " to catch the ";
        if (j == 1) {

            out << "fly.\n";
        } else if (j == 2) {
            out << "spider that wriggled and jiggled and tickled inside her.\n";
        } else {
            out << animals[j - 1].name << ".\n";
        }}
    out << "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    
        return out.str();
    }

    std::string verses(int start, int end) {
        std::ostringstream out;
        for (int v = start;v <= end; ++v) {
            out << verse(v);
            out << "\n";
        }
        return out.str();
    }

    std::string sing() {
        return verses(1, 8);
    }
    
}  // namespace food_chain    
