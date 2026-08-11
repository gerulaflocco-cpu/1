#include "space_age.h"

namespace space_age {
    static constexpr double EARTH_YEAR =  31557600.0;
    
    double space_age::seconds() const {return seconds_;}
    double space_age::on_earth() const {return seconds_  / EARTH_YEAR ;}
    double space_age::on_mercury() const {return seconds_  / EARTH_YEAR / 0.2408467;}
    double space_age::on_venus() const {return seconds_  / EARTH_YEAR / 0.61519726;}
    double space_age::on_mars() const {return seconds_  / EARTH_YEAR / 1.8808158;}
    double space_age::on_jupiter() const {return seconds_  / EARTH_YEAR / 11.862615;}
    double space_age::on_saturn() const {return seconds_  / EARTH_YEAR / 29.447498;}
    double space_age::on_uranus() const {return seconds_  / EARTH_YEAR / 84.016846;}
    double space_age::on_neptune() const {return seconds_  / EARTH_YEAR / 164.79132;}
    
}  // namespace space_age
