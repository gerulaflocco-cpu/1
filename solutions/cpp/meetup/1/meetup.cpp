#include "meetup.h"

namespace meetup {

using namespace boost::gregorian;

scheduler::scheduler(boost::gregorian::months_of_year month, int year)
:month_(month), year_(year) {}

date    scheduler::teenth(boost::gregorian::greg_weekday wd) const {
    for (int day = 13; day <= 19; ++day) {
        date d(year_, month_, day);
        if (d.day_of_week() == wd)
            return d;
    }
    return {};
}

date scheduler::nth(int n, boost::gregorian::greg_weekday wd) const {
date d(year_, month_, 1);
    int count = 0;
    date end = d.end_of_month();
    while (d <= end) {
        if (d.day_of_week() == wd) {
            ++count;
            if (count == n)return d;
            
        }
        d += days(1);
    }
    return {};
}

    date scheduler::last(boost::gregorian::greg_weekday wd) const {
        date d = date(year_, month_, 1).end_of_month();
        while(d.day_of_week() != wd)
            d -= days(1);
        return d;
    }
    date scheduler::monteenth()    const { return teenth(Monday); }
date scheduler::tuesteenth()   const { return teenth(Tuesday); }
date scheduler::wednesteenth() const { return teenth(Wednesday); }
date scheduler::thursteenth()  const { return teenth(Thursday); }
date scheduler::friteenth()    const { return teenth(Friday); }
date scheduler::saturteenth()  const { return teenth(Saturday); }
date scheduler::sunteenth()    const { return teenth(Sunday); }

// first 系列
date scheduler::first_monday()    const { return nth(1, Monday); }
date scheduler::first_tuesday()   const { return nth(1, Tuesday); }
date scheduler::first_wednesday() const { return nth(1, Wednesday); }
date scheduler::first_thursday()  const { return nth(1, Thursday); }
date scheduler::first_friday()    const { return nth(1, Friday); }
date scheduler::first_saturday()  const { return nth(1, Saturday); }
date scheduler::first_sunday()    const { return nth(1, Sunday); }

// second 系列
date scheduler::second_monday()    const { return nth(2, Monday); }
date scheduler::second_tuesday()   const { return nth(2, Tuesday); }
date scheduler::second_wednesday() const { return nth(2, Wednesday); }
date scheduler::second_thursday()  const { return nth(2, Thursday); }
date scheduler::second_friday()    const { return nth(2, Friday); }
date scheduler::second_saturday()  const { return nth(2, Saturday); }
date scheduler::second_sunday()    const { return nth(2, Sunday); }

// third 系列
date scheduler::third_monday()    const { return nth(3, Monday); }
date scheduler::third_tuesday()   const { return nth(3, Tuesday); }
date scheduler::third_wednesday() const { return nth(3, Wednesday); }
date scheduler::third_thursday()  const { return nth(3, Thursday); }
date scheduler::third_friday()    const { return nth(3, Friday); }
date scheduler::third_saturday()  const { return nth(3, Saturday); }
date scheduler::third_sunday()    const { return nth(3, Sunday); }

// fourth 系列
date scheduler::fourth_monday()    const { return nth(4, Monday); }
date scheduler::fourth_tuesday()   const { return nth(4, Tuesday); }
date scheduler::fourth_wednesday() const { return nth(4, Wednesday); }
date scheduler::fourth_thursday()  const { return nth(4, Thursday); }
date scheduler::fourth_friday()    const { return nth(4, Friday); }
date scheduler::fourth_saturday()  const { return nth(4, Saturday); }
date scheduler::fourth_sunday()    const { return nth(4, Sunday); }

// last 系列
date scheduler::last_monday()    const { return last(Monday); }
date scheduler::last_tuesday()   const { return last(Tuesday); }
date scheduler::last_wednesday() const { return last(Wednesday); }
date scheduler::last_thursday()  const { return last(Thursday); }
date scheduler::last_friday()    const { return last(Friday); }
date scheduler::last_saturday()  const { return last(Saturday); }
date scheduler::last_sunday()    const { return last(Sunday); }
}  
