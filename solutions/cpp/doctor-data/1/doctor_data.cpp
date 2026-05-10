#include "doctor_data.h"

namespace heaven {
    Vessel::Vessel(std::string name, int capacity, star_map::System system)
    : name{name}, capacity{capacity}, current_system{system}, generation{1} {}
    
    Vessel Vessel::replicate(std::string name) {
         Vessel v{name, capacity, current_system};
        v.generation =generation + 1;
        return v;
    }

    void Vessel::make_buster() {
        busters += 1;
    }
    bool Vessel::shoot_buster() {
        if (busters>0) {
            busters -= 1;
            return true;
        }
        return false;
    }
    
    std::string get_older_bob(Vessel a, Vessel b) {
        if (a.generation >= b.generation) return a.name;
        return b.name;    
    }

    bool in_the_same_system(Vessel a, Vessel b) {
        return a.current_system == b.current_system;
    }
}