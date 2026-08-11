#include "kindergarten_garden.h"
#include <array>
#include <algorithm>

namespace kindergarten_garden {

namespace {

Plants char_to_plant(char c) {
    switch (c) {
        case 'G': return Plants::grass;
        case 'C': return Plants::clover;
        case 'R': return Plants::radishes;
        case 'V': return Plants::violets;
    }
    return Plants::grass;  // 不会到达，保险起见
}

}  // namespace

std::array<Plants, 4> plants(std::string diagram, std::string student) {
    static const std::array<std::string, 12> students{
        "Alice",   "Bob",     "Charlie", "David",  "Eve",   "Fred",
        "Ginny",   "Harriet", "Ileana",  "Joseph", "Kincaid", "Larry"};

    int index = static_cast<int>(
        std::distance(students.begin(),
                      std::find(students.begin(), students.end(), student)));

    int start = index * 2;

    // 找到换行符，把两行分开
    auto newline_pos = diagram.find('\n');
    std::string row1 = diagram.substr(0, newline_pos);
    std::string row2 = diagram.substr(newline_pos + 1);

    return {char_to_plant(row1[start]), char_to_plant(row1[start + 1]),
            char_to_plant(row2[start]), char_to_plant(row2[start + 1])};
}

}  // namespace kindergarten_garden