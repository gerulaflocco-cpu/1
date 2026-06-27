#include "flower_field.h"

namespace flower_field {

    // 8个方向：上、下、左、右 + 4个斜角
    const int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    int count_flowers(const std::vector<std::string>& garden, int row, int col) {
        if (garden.empty() || garden[0].empty()) return 0;

        int rows = garden.size();
        int cols = garden[0].size();
        int count = 0;

        for (const auto& dir : directions) {
            int r = row + dir[0];
            int c = col + dir[1];

            if (r >= 0 && r < rows && c >= 0 && c < cols && garden[r][c] == '*') {
                count++;
            }
        }
        return count;
    }

    std::vector<std::string> annotate(const std::vector<std::string>& garden) {
        if (garden.empty()) return {};

        int rows = garden.size();
        if (rows == 0 || garden[0].empty()) {
            return {""};  // 处理空行情况
        }

        int cols = garden[0].size();
        std::vector<std::string> result = garden;  // 复制一份

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (garden[i][j] == ' ') {
                    int num = count_flowers(garden, i, j);
                    if (num > 0) {
                        result[i][j] = '0' + num;  // 数字转字符
                    }
                    // 如果 num == 0 就保持空格
                }
                // 如果是 '*' 则不修改
            }
        }

        return result;
    }

} // namespace flower_field