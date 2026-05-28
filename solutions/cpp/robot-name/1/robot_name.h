#pragma once
#include <vector>
#include <unordered_set>
#include <string>
namespace robot_name {

class robot {
    public:
    robot();
    const std::string & name() const;
    void reset();

private:
    std::string name_;
    static std::unordered_set<std::string> used_names_;

    static std::string generate_unique_name();
    
};

}  // namespace robot_name
