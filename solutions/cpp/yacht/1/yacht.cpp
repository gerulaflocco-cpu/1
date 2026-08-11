#include "yacht.h"
#include <algorithm>
#include <array>
#include <numeric>

namespace yacht {

namespace {

std::array<int, 7> tally(const std::vector<int>& dice) {
    std::array<int, 7> counts{};
    for (int d : dice) {
        counts[d]++;
    }
    return counts;
}

}  // namespace

int score(std::vector<int> dice, std::string category) {
    auto counts = tally(dice);
    int sum = std::accumulate(dice.begin(), dice.end(), 0);

    if (category == "ones") return counts[1] * 1;
    if (category == "twos") return counts[2] * 2;
    if (category == "threes") return counts[3] * 3;
    if (category == "fours") return counts[4] * 4;
    if (category == "fives") return counts[5] * 5;
    if (category == "sixes") return counts[6] * 6;

    if (category == "full house") {
        bool has_three = false;
        bool has_two = false;
        for (int face = 1; face <= 6; ++face) {
            if (counts[face] == 3) has_three = true;
            if (counts[face] == 2) has_two = true;
        }
        return (has_three && has_two) ? sum : 0;
    }

    if (category == "four of a kind") {
        for (int face = 1; face <= 6; ++face) {
            if (counts[face] >= 4) return face * 4;
        }
        return 0;
    }

    if (category == "little straight") {
        return (counts[1] == 1 && counts[2] == 1 && counts[3] == 1 &&
                counts[4] == 1 && counts[5] == 1) ? 30 : 0;
    }

    if (category == "big straight") {
        return (counts[2] == 1 && counts[3] == 1 && counts[4] == 1 &&
                counts[5] == 1 && counts[6] == 1) ? 30 : 0;
    }

    if (category == "choice") {
        return sum;
    }

    if (category == "yacht") {
        for (int face = 1; face <= 6; ++face) {
            if (counts[face] == 5) return 50;
        }
        return 0;
    }

    return 0;
}

}  // namespace yacht