#pragma once
#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school {
public:
    void add(const std::string& name, int grade);
    std::map<int, std::vector<std::string>> roster() const;
    std::vector<std::string> grade(int g) const;

private:
    std::map<int, std::vector<std::string>> students_;
};


}  // namespace grade_school
