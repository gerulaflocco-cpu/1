#include "clock.h"
#include <iomanip>
#include <sstream>
namespace date_independent {

namespace {
    int mod(int n, int m) {
        return (( n % m) + m) % m;

        
    };
}

clock::clock(int total_minutes)
    : minutes_(mod(total_minutes, 1440)) {}


    clock clock::at(int hour, int minute) {
        return clock(hour * 60 + minute);
    }


  clock  clock::plus(int minutes) const {
        return clock(minutes_ + minutes);
    }
    



    clock::operator std::string() const {
        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(2) << (minutes_ / 60)
            << ':'
            << std::setw(2) << (minutes_ % 60);
        return oss.str();
    }



   bool clock::operator==(const clock& other) const {
       return minutes_ == other.minutes_;
   }


   bool clock::operator!=(const clock& other) const {
       return !(*this == other);
   }

}  // namespace date_independent
