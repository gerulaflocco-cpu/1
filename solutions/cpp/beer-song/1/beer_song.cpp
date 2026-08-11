#include "beer_song.h"
#include <sstream>
namespace beer_song {

static std::string bottles(int n) {
    if (n == 0) return "no more bottles";
    if (n == 1) return "1 bottle";
    return std::to_string(n) + " bottles";
}


    std::string verse(int number) {
          std::ostringstream oss;
        if (number == 0) {
            oss << "No more bottles of beer on the wall, no more bottles of beer.\n"
                << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        } else {
            std::string next = bottles(number - 1);
            std::string action = ( number == 1) ? "Take it down" : "Take one down";
            oss << bottles(number) << " of beer on the wall, "
                << bottles(number) << " of beer.\n"  
                << action << " and pass it around, "
                << next << " of beer on the wall.\n";
        }
        return oss.str();
    }

        std::string sing(int from, int to) {
              std::ostringstream oss;
            for (int i = from; i > to; --i) {
                oss << verse(i);
                oss << "\n";
            }
            oss << verse(to);
            return oss.str();
        }

    std::string sing(int from) {
        return sing(from, 0);
    }
    
}  
