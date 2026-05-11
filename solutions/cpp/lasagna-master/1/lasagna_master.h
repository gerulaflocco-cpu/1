#pragma once
#include <string>
#include <vector>
namespace lasagna_master {

struct amount {
    int noodles{};
    double sauce{};
};

int preparationTime(std::vector<std::string> layers, int avg_time =2);
amount quantities(std::vector<std::string> layers);
void addSecretIngredient(std::vector<std::string>& mylist, 
                         const std::vector<std::string>& friendlist);
void addSecretIngredient(std::vector<std::string>& mylist, const std::string& secretIngredient);
std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);

}  // namespace lasagna_master
