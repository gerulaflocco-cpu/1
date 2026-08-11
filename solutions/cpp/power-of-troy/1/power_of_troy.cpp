#include "power_of_troy.h"

namespace troy {
void give_new_artifact(human& person  , const std::string& name) {
    person.possession = std::make_unique<artifact>(name);
}
    
    void exchange_artifacts(std::unique_ptr<artifact>& a, std::unique_ptr<artifact>& b) {
    std::swap(a, b);
    }

void manifest_power (human& person, const std::string& effect){
    person.own_power = std::make_shared<power>(effect);
}

void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(const human& person) {
    if (!person.own_power) return 0;
    return static_cast<int>(person.own_power.use_count());    
}
}  // namespace troy
