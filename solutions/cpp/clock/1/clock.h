#pragma once
#include <string>
namespace date_independent {

class clock {
public:
    static clock at(int hour, int minute);
    clock plus(int minutes) const;
    operator std::string() const;
    bool operator==(const clock& other) const;
    bool operator!=(const clock& other) const;


private:
    int minutes_;
    explicit clock(int total_minutes);
};
}
