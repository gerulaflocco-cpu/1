#pragma once
#include <string>
#include <unordered_set>
#include <vector>
namespace allergies {

class allergy_test {
 public:
    allergy_test(unsigned score);
    bool is_allergic_to(const std::string& allergen) const;
    std::unordered_set<std::string> get_allergies() const;


private:
    unsigned score;

};
}// namespace allergies
