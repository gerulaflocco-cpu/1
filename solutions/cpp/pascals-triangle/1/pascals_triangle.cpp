// pascals_triangle.cpp
#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(int count) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < count; i++) {
        std::vector<int> row(i + 1, 1);  // 新行，长度i+1，全填1

        // 中间的值 = 上一行左边 + 上一行右边
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

}  // namespace pascals_triangle