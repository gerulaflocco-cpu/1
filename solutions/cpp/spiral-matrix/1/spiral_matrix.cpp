#include "spiral_matrix.h"

namespace spiral_matrix {

std::vector<std::vector<uint32_t>> spiral_matrix(int size) {
    std::vector<std::vector<uint32_t>> matrix(
        size, std::vector<uint32_t>(size, 0));

    if (size == 0) {
        return matrix;
    }

    int top = 0, bottom = size - 1;
    int left = 0, right = size - 1;
    uint32_t value = 1;

    while (top <= bottom && left <= right) {
        // 从左到右填最上面一行
        for (int col = left; col <= right; ++col) {
            matrix[top][col] = value++;
        }
        ++top;

        // 从上到下填最右边一列
        for (int row = top; row <= bottom; ++row) {
            matrix[row][right] = value++;
        }
        --right;

        // 从右到左填最下面一行（如果还有行）
        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                matrix[bottom][col] = value++;
            }
            --bottom;
        }

        // 从下到上填最左边一列（如果还有列）
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                matrix[row][left] = value++;
            }
            ++left;
        }
    }

    return matrix;
}

}  // namespace spiral_matrix