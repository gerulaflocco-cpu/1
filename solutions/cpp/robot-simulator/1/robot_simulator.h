// robot_simulator.h
#pragma once
#include <string>
#include <utility> // std::pair

namespace robot_simulator {

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
public:
    // 默认构造：位置 (0,0)，朝向 NORTH
    Robot() : position_{0, 0}, bearing_{Bearing::NORTH} {}

    // 带参构造
    Robot(std::pair<int,int> position, Bearing bearing)
        : position_{position}, bearing_{bearing} {}

    std::pair<int,int> get_position() const { return position_; }
    Bearing get_bearing() const { return bearing_; }

    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string& instructions);

private:
    std::pair<int,int> position_;
    Bearing bearing_;
};

} // namespace robot_simulator