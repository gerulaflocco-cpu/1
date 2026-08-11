#include "allergies.h"
#include <vector>
namespace allergies {

    allergy_test::allergy_test(unsigned score) : score(score) {}

const std::vector<std::pair<unsigned, std::string>> allergens = {
    {1, "eggs" },
    {2, "peanuts" },
     {4, "shellfish" },
      {8, "strawberries" },
       {16, "tomatoes" },
        {32, "chocolate" },
         {64, "pollen" },
          {128    , "cats" },
};

bool allergy_test::is_allergic_to(const std::string& allergen) const {
    for (const auto& [value, name] : allergens ){
        if (name == allergen && (score & value)) return true;
    }
    return false;
}

std::unordered_set<std::string>  allergy_test::get_allergies() const {
    std::unordered_set<std::string> result;
    for (const auto& [value, name] : allergens) {
        if (score & value) result.emplace(name);
    }
    return result;
}
}  // namespace allergies
