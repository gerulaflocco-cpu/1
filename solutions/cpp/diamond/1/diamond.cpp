#include "diamond.h"
#include <string>
#include <vector>

namespace diamond {

std::vector<std::string> rows(char letter) {
    int n = letter - 'A';
    // 删掉了 int width = 2 * n + 1;

    std::vector<std::string> upper;
    for (int i = 0; i <= n; i++) {
        char c = 'A' + i;
        int outer = n - i;
        std::string row(outer, ' ');

        if (i == 0) {
            row += 'A';
            row += std::string(outer, ' ');
        } else {
            int inner = 2 * i - 1;
            row += c;
            row += std::string(inner, ' ');
            row += c;
            row += std::string(outer, ' ');
        }
        upper.push_back(row);
    }

    std::vector<std::string> result = upper;
    for (int i = upper.size() - 2; i >= 0; i--) {
        result.push_back(upper[i]);
    }

    return result;
}

}  // namespace diamond