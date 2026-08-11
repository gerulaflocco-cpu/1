// perfect_numbers.cpp
#include "perfect_numbers.h"

namespace perfect_numbers {

classification classify(int n) {
    if (n <= 0) {
        throw std::domain_error("只有正整数才能被分类");
    }

    int aliquot_sum = 1; // 1 始终是因子（n > 1 时）
    
    if (n == 1) {
        aliquot_sum = 0; // 1 没有除自身以外的因子
    } else {
        // 从 2 遍历到 sqrt(n)，成对添加因子
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                aliquot_sum += i;
                if (i != n / i) {       // 避免重复计算完全平方根
                    aliquot_sum += n / i;
                }
            }
        }
    }

    if (aliquot_sum == n) return classification::perfect;
    if (aliquot_sum >  n) return classification::abundant;
    return classification::deficient;
}

} // namespace perfect_numbers