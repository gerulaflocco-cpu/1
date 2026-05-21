#include "queen_attack.h"
#include <cstdlib>
namespace queen_attack {

 void chess_board::validate(std::pair<int, int> pos) {
     if (pos.first < 0 || pos.first > 7 ||
         pos.second < 0 || pos.second > 7) {
         throw std::domain_error("queen position out of bounds");
         }}

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : white_(white), black_(black)
{
    validate(white);
    validate(black);
    if(white == black)
        throw std::domain_error("queens cannot occupy the same position");
}
     
bool chess_board::can_attack() const {
    int dr = std::abs(white_.first - black_.first);
    int dc = std::abs(white_.second - black_.second);

    return dr == 0
        || dc == 0
        || dr == dc;
}

}  // namespace queen_attack
