#include "dnd_character.h"
#include <algorithm>
#include <array>
#include <random>

namespace dnd_character {

namespace {

int roll_die() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(1, 6);
    return dist(gen);
}

}  // namespace

int modifier(int score) {
    return (score - 10) / 2 - ((score - 10) % 2 != 0 && (score - 10) < 0 ? 1 : 0);
}

int ability() {
    std::array<int, 4> rolls{roll_die(), roll_die(), roll_die(), roll_die()};
    std::sort(rolls.begin(), rolls.end());
    // 丢掉最小的一个（已排序后下标0），加总剩下三个
    return rolls[1] + rolls[2] + rolls[3];
}

Character::Character()
    : strength(ability()),
      dexterity(ability()),
      constitution(ability()),
      intelligence(ability()),
      wisdom(ability()),
      charisma(ability()),
      hitpoints(10 + modifier(constitution)) {}

}  // namespace dnd_character