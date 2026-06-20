// robot_simulator.cpp
#include "robot_simulator.h"

namespace robot_simulator {

void Robot::turn_right() {
    switch (bearing_) {
        case Bearing::NORTH: bearing_ = Bearing::EAST;  break;
        case Bearing::EAST:  bearing_ = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing_ = Bearing::WEST;  break;
        case Bearing::WEST:  bearing_ = Bearing::NORTH; break;
    }
}

void Robot::turn_left() {
    switch (bearing_) {
        case Bearing::NORTH: bearing_ = Bearing::WEST;  break;
        case Bearing::WEST:  bearing_ = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing_ = Bearing::EAST;  break;
        case Bearing::EAST:  bearing_ = Bearing::NORTH; break;
    }
}

void Robot::advance() {
    switch (bearing_) {
        case Bearing::NORTH: position_.second += 1; break; // y+1
        case Bearing::SOUTH: position_.second -= 1; break; // y-1
        case Bearing::EAST:  position_.first  += 1; break; // x+1
        case Bearing::WEST:  position_.first  -= 1; break; // x-1
    }
}

void Robot::execute_sequence(const std::string& instructions) {
    for (char cmd : instructions) {
        switch (cmd) {
            case 'R': turn_right(); break;
            case 'L': turn_left();  break;
            case 'A': advance();    break;
        }
    }
}

} // namespace robot_simulator