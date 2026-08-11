#include "knapsack.h"

#include <vector>

namespace knapsack {

int maximum_value(int max_weight, const std::vector<Item>& items) {
    // dp[w] 表示在背包容量为 w 时能取得的最大价值
    std::vector<int> dp(max_weight + 1, 0);

    for (const auto& item : items) {
        // 从大到小遍历容量，保证每个物品只被用一次（0/1背包）
        for (int w = max_weight; w >= item.weight; --w) {
            int candidate = dp[w - item.weight] + item.value;
            if (candidate > dp[w]) {
                dp[w] = candidate;
            }
        }
    }

    return dp[max_weight];
}

}  // namespace knapsack