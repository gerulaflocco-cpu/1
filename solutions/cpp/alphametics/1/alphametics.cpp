#include "alphametics.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <functional>   // ← 补上这一行
#include <set>
#include <sstream>
#include <vector>
namespace alphametics {

namespace {

std::vector<std::string> split(const std::string& s, const std::string& delim) {
    std::vector<std::string> result;
    size_t start = 0;
    while (true) {
        size_t pos = s.find(delim, start);
        if (pos == std::string::npos) {
            result.push_back(s.substr(start));
            break;
        }
        result.push_back(s.substr(start, pos - start));
        start = pos + delim.size();
    }
    return result;
}

std::string trim(const std::string& s) {
    size_t b = s.find_first_not_of(" \t");
    size_t e = s.find_last_not_of(" \t");
    if (b == std::string::npos) return "";
    return s.substr(b, e - b + 1);
}

}  // namespace

std::optional<std::map<char, int>> solve(const std::string& puzzle) {
    // 解析 "A + B + C == D"
    auto sides = split(puzzle, "==");
    auto lhs_str = trim(sides[0]);
    auto rhs_str = trim(sides[1]);

    std::vector<std::string> words;
    for (auto& w : split(lhs_str, "+")) {
        words.push_back(trim(w));
    }
    std::string rhs = rhs_str;

    // 收集所有出现的字母，及"首字母"集合（不能为0）
    std::set<char> letters_set;
    std::set<char> leading;
    for (auto& w : words) {
        leading.insert(w.front());
        for (char c : w) letters_set.insert(c);
    }
    leading.insert(rhs.front());
    for (char c : rhs) letters_set.insert(c);

    std::vector<char> letters(letters_set.begin(), letters_set.end());
    int n = static_cast<int>(letters.size());

    if (n > 10) {
        return std::nullopt;  // 数字只有0~9，字母不能超过10个
    }

    // letter -> 在等式中的系数 (左边加，右边减)
    std::map<char, long long> coeff;
    for (char c : letters) coeff[c] = 0;

    auto add_word = [&](const std::string& w, int sign) {
        long long place = 1;
        for (int i = static_cast<int>(w.size()) - 1; i >= 0; --i) {
            coeff[w[i]] += sign * place;
            place *= 10;
        }
    };

    for (auto& w : words) add_word(w, +1);
    add_word(rhs, -1);

    // letter -> index，方便用数组存放系数，加速递归
    std::map<char, int> letter_index;
    for (int i = 0; i < n; ++i) letter_index[letters[i]] = i;

    std::vector<long long> coeffs(n);
    for (int i = 0; i < n; ++i) coeffs[i] = coeff[letters[i]];

    std::vector<bool> is_leading(n, false);
    for (int i = 0; i < n; ++i) {
        if (leading.count(letters[i])) is_leading[i] = true;
    }

    std::array<bool, 10> used{};
    std::vector<int> assigned(n, -1);

    // 递归尝试给每个字母分配数字
    std::function<bool(int, long long)> backtrack = [&](int idx, long long partial_sum) -> bool {
        if (idx == n) {
            return partial_sum == 0;
        }
        for (int digit = 0; digit <= 9; ++digit) {
            if (used[digit]) continue;
            if (digit == 0 && is_leading[idx]) continue;  // 首位不能是0

            used[digit] = true;
            assigned[idx] = digit;

            if (backtrack(idx + 1, partial_sum + coeffs[idx] * digit)) {
                return true;
            }

            used[digit] = false;
            assigned[idx] = -1;
        }
        return false;
    };

    if (backtrack(0, 0)) {
        std::map<char, int> result;
        for (int i = 0; i < n; ++i) {
            result[letters[i]] = assigned[i];
        }
        return result;
    }

    return std::nullopt;
}

}  // namespace alphametics