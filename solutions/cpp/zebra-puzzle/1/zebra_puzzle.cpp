#include "zebra_puzzle.h"

#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace zebra_puzzle {

namespace {

constexpr int kHouses = 5;

int indexOf(const std::array<std::string, kHouses>& arr, const std::string& value) {
    for (int i = 0; i < kHouses; ++i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

bool nextToEachOther(int a, int b) { return std::abs(a - b) == 1; }

}  // namespace

Solution solve() {
    std::array<std::string, kHouses> colors = {"Red", "Green", "Ivory", "Yellow", "Blue"};
    std::array<std::string, kHouses> nationalities = {"Englishman", "Spaniard", "Ukrainian",
                                                        "Norwegian", "Japanese"};
    std::array<std::string, kHouses> drinks = {"Coffee", "Tea", "Milk", "Orange juice", "Water"};
    std::array<std::string, kHouses> pets = {"Dog", "Snails", "Fox", "Horse", "Zebra"};
    std::array<std::string, kHouses> hobbies = {"Dancing", "Painting", "Reading", "Football",
                                                 "Chess"};

    std::array<int, kHouses> baseOrder = {0, 1, 2, 3, 4};

    auto colorPerm = baseOrder;
    do {
        std::array<std::string, kHouses> colorArr;
        for (int i = 0; i < kHouses; ++i) colorArr[i] = colors[colorPerm[i]];

        // 第6条：绿房子在象牙色房子右边
        int greenIdx = indexOf(colorArr, "Green");
        int ivoryIdx = indexOf(colorArr, "Ivory");
        if (greenIdx - ivoryIdx != 1) continue;

        auto natPerm = baseOrder;
        do {
            std::array<std::string, kHouses> natArr;
            for (int i = 0; i < kHouses; ++i) natArr[i] = nationalities[natPerm[i]];

            // 第2条：英国人住红房子
            int engIdx = indexOf(natArr, "Englishman");
            int redIdx = indexOf(colorArr, "Red");
            if (engIdx != redIdx) continue;

            // 第10条：挪威人住第一栋
            int norIdx = indexOf(natArr, "Norwegian");
            if (norIdx != 0) continue;

            // 第15条：挪威人住蓝房子旁边
            int blueIdx = indexOf(colorArr, "Blue");
            if (!nextToEachOther(norIdx, blueIdx)) continue;

            auto drinkPerm = baseOrder;
            do {
                std::array<std::string, kHouses> drinkArr;
                for (int i = 0; i < kHouses; ++i) drinkArr[i] = drinks[drinkPerm[i]];

                // 第5条：乌克兰人喝茶
                int ukrIdx = indexOf(natArr, "Ukrainian");
                int teaIdx = indexOf(drinkArr, "Tea");
                if (ukrIdx != teaIdx) continue;

                // 第9条：中间那户喝牛奶
                if (drinkArr[2] != "Milk") continue;

                auto hobbyPerm = baseOrder;
                do {
                    std::array<std::string, kHouses> hobbyArr;
                    for (int i = 0; i < kHouses; ++i) hobbyArr[i] = hobbies[hobbyPerm[i]];

                    // 第4条：绿房子的人喝咖啡
                    int coffeeIdx = indexOf(drinkArr, "Coffee");
                    if (coffeeIdx != greenIdx) continue;

                    // 第8条：黄房子的人是画家
                    int paintIdx = indexOf(hobbyArr, "Painting");
                    int yellowIdx = indexOf(colorArr, "Yellow");
                    if (paintIdx != yellowIdx) continue;

                    // 第13条：踢足球的人喝橙汁
                    int footballIdx = indexOf(hobbyArr, "Football");
                    int ojIdx = indexOf(drinkArr, "Orange juice");
                    if (footballIdx != ojIdx) continue;

                    // 第14条：日本人下国际象棋
                    int japIdx = indexOf(natArr, "Japanese");
                    int chessIdx = indexOf(hobbyArr, "Chess");
                    if (japIdx != chessIdx) continue;

                    auto petPerm = baseOrder;
                    do {
                        std::array<std::string, kHouses> petArr;
                        for (int i = 0; i < kHouses; ++i) petArr[i] = pets[petPerm[i]];

                        // 第3条：西班牙人养狗
                        int spaIdx = indexOf(natArr, "Spaniard");
                        int dogIdx = indexOf(petArr, "Dog");
                        if (spaIdx != dogIdx) continue;

                        // 第7条：养蜗牛的人喜欢跳舞
                        int snailIdx = indexOf(petArr, "Snails");
                        int danceIdx = indexOf(hobbyArr, "Dancing");
                        if (snailIdx != danceIdx) continue;

                        // 第11条：喜欢读书的人住在养狐狸的人旁边
                        int readIdx = indexOf(hobbyArr, "Reading");
                        int foxIdx = indexOf(petArr, "Fox");
                        if (!nextToEachOther(readIdx, foxIdx)) continue;

                        // 第12条：画家住在养马的人旁边
                        int horseIdx = indexOf(petArr, "Horse");
                        if (!nextToEachOther(paintIdx, horseIdx)) continue;

                        // 所有约束都满足，找到解
                        Solution sol;
                        int waterIdx = indexOf(drinkArr, "Water");
                        int zebraIdx = indexOf(petArr, "Zebra");
                        sol.drinksWater = natArr[waterIdx];
                        sol.ownsZebra = natArr[zebraIdx];
                        return sol;

                    } while (std::next_permutation(petPerm.begin(), petPerm.end()));
                } while (std::next_permutation(hobbyPerm.begin(), hobbyPerm.end()));
            } while (std::next_permutation(drinkPerm.begin(), drinkPerm.end()));
        } while (std::next_permutation(natPerm.begin(), natPerm.end()));
    } while (std::next_permutation(colorPerm.begin(), colorPerm.end()));

    return Solution{};
}

}  // namespace zebra_puzzle