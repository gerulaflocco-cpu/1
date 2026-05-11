#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(std::vector<std::string> layers, int avg_time) {
    return layers.size() * avg_time;
}

    amount quantities(std::vector<std::string> layers) {
        amount result ;
        for (const auto& layer : layers){
        if (layer == "noodles") {
            result.noodles += 50;
        }
        else if (layer == "sauce") {
            result.sauce += 0.2;
        }
        }
        return result;}

        void addSecretIngredient(std::vector<std::string>& mylist, 
                                 const std::vector<std::string>& friendlist) {
            mylist.back() = friendlist.back();
                                 }

        std::vector<double> scaleRecipe(std::vector<double> quantities, int portions) {
            std::vector<double> scaled{};
            for (double q : quantities) {
                scaled.push_back(q / 2.0 * portions);
            }
            return scaled;
        }

void addSecretIngredient(std::vector<std::string>& mylist, const std::string& secretIngredient) {
    mylist.back() = secretIngredient;
}
    }
  // namespace lasagna_master
