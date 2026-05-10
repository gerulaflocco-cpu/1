#pragma once
#include <string>

namespace star_map {
    enum class System  {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
    public:
        Vessel(std::string name, int capacity, star_map::System system = star_map::System::Sol);

        Vessel replicate(std::string name);
        void make_buster();
        bool shoot_buster(); 
      

        std::string name;
        int capacity;
        star_map::System current_system;
        int generation;
        int busters{0};
    };
      std::string get_older_bob(Vessel a, Vessel b);
      bool in_the_same_system(Vessel a, Vessel b);
}