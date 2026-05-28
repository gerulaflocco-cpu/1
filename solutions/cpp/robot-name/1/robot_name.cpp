#include "robot_name.h"
#include <random>
#include <stdexcept>

namespace robot_name {

std::unordered_set<std::string> robot::used_names_;

    static std::string generate_name() {
        static std::mt19937 rng{std::random_device{}()};
        static std::uniform_int_distribution<> letter_dist('A', 'Z');
        static std::uniform_int_distribution<> digit_dist('0', '9');

        std::string name(5, ' ');
        name[0] = letter_dist(rng);
        name[1] = letter_dist(rng);
        name[2] = digit_dist(rng);
        name[3] = digit_dist(rng);
        name[4] = digit_dist(rng);
        return name;
    }

    std::string robot::generate_unique_name() {
        if(used_names_.size() >= 676000)
            throw std::runtime_error("No avaliable name left");

    std::string name;
        do {
            name = generate_name();
            
        }while (used_names_.count(name));

        used_names_.insert(name);
        return name;
    }
    robot::robot() : name_(generate_unique_name()) {}

    const std::string & robot::name() const {
        return name_;
    }

    void robot::reset() {
        name_ = generate_unique_name();
    }
}  // namespace robot_name
