#include "twelve_days.h"

#include <string>
#include <vector>

namespace twelve_days {

// 天数
static const std::vector<std::string> days = {
    "",
    "first", "second", "third", "fourth", "fifth", "sixth",
    "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
};

// 礼物
static const std::vector<std::string> gifts = {
    "",
    "a Partridge in a Pear Tree",
    "two Turtle Doves",
    "three French Hens",
    "four Calling Birds",
    "five Gold Rings",
    "six Geese-a-Laying",
    "seven Swans-a-Swimming",
    "eight Maids-a-Milking",
    "nine Ladies Dancing",
    "ten Lords-a-Leaping",
    "eleven Pipers Piping",
    "twelve Drummers Drumming"
};

// 单节歌词
static std::string verse(int n) {
    std::string s;

    s += "On the " + days[n]
       + " day of Christmas my true love gave to me: ";

    if (n == 1) {
        return s + gifts[1] + ".\n";
    }

    for (int i = n; i >= 2; --i) {
        s += gifts[i] + ", ";
    }

    s += "and " + gifts[1] + ".";

    return s + "\n";
}

// 主函数：区间输出
std::string recite(int start, int end) {
    std::string out;

    for (int i = start; i <= end; ++i) {
        out += verse(i);

        if (i != end) {
            out += "\n";
        }
    }

    return out;
}

}  // namespace twelve_days