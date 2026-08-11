#pragma once
#include <utility>
#include <stdexcept>

namespace queen_attack {

class chess_board {
public:
    chess_board(std::pair<int, int> white, std::pair<int, int> black);

    std::pair<int, int> white() const { return white_; }
    std::pair<int, int> black() const { return black_; }
    bool   can_attack() const;

private:
    std::pair<int, int> white_;
    std::pair<int, int> black_;

    static void validate(std::pair<int, int> pos);
};

}  // namespace queen_attack
