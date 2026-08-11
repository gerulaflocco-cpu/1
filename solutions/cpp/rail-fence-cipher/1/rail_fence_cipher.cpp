#include "rail_fence_cipher.h"
#include <vector>
#include <string>

namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails) {
    if (num_rails <= 1 || plaintext.empty()) return plaintext;

    std::vector<std::string> rails(num_rails);
    int row = 0, dir = 1;

    for (char c : plaintext) {
        rails[row] += c;
        row += dir;
        if (row == num_rails - 1) dir = -1;
        else if (row == 0) dir = 1;
    }

    std::string result;
    for (const auto& r : rails) result += r;
    return result;
}

std::string decode(const std::string& ciphertext, int num_rails) {
    if (num_rails <= 1 || ciphertext.empty()) return ciphertext;

    int n = ciphertext.size();
    std::vector<std::vector<int>> rail_pos(num_rails);

    int row = 0, dir = 1;
    for (int i = 0; i < n; ++i) {
        rail_pos[row].push_back(i);
        row += dir;
        if (row == num_rails - 1) dir = -1;
        else if (row == 0) dir = 1;
    }

    std::string result(n, ' ');
    int idx = 0;
    for (const auto& positions : rail_pos) {
        for (int p : positions) {
            result[p] = ciphertext[idx++];
        }
    }
    return result;
}

}  // namespace rail_fence_cipher