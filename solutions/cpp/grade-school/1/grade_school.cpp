#include "grade_school.h"
#include <algorithm>
namespace grade_school {

void school::add(const std::string& name, int grade) {
    auto& vec = students_[grade];
    if (std::find(vec.begin(), vec.end(), name) != vec.end())
        return;
    vec.push_back(name);
    std::sort(vec.begin(), vec.end());
}

std::map<int, std::vector<std::string>> school::roster() const {
    return students_;
}

std::vector<std::string> school::grade(int g) const {
    auto it = students_.find(g);
    if (it == students_.end())
        return {};
    return it->second;
}
}  // namespace grade_school
