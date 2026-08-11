#include "affine_cipher.h"

#include <algorithm>
#include <cctype>
#include <numeric>
#include <stdexcept>
#include <string>

namespace affine_cipher {

const int M = 26;

// 求模逆元（暴力法，m=26足够用）
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; ++x) {
        if ((static_cast<long long>(a) * x % m) == 1) {
            return x;
        }
    }
    return -1;
}

// 判断互质
bool is_coprime(int a, int m) {
    return std::gcd(a, m) == 1;
}

// 加密
std::string encode(const std::string& plaintext, int a, int b) {
    if (!is_coprime(a, M)) {
        throw std::invalid_argument("a and m must be coprime.");
    }

    // 1️⃣ 先生成连续字符（无空格分组）
    std::string raw;

    for (char c : plaintext) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            int x = std::tolower(c) - 'a';
            int enc = (static_cast<long long>(a) * x + b) % M;
            raw += static_cast<char>('a' + enc);
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            raw += c;
        }
    }

    // 2️⃣ 再按5个一组分割
    std::string result;
    for (size_t i = 0; i < raw.size(); ++i) {
        if (i > 0 && i % 5 == 0) {
            result += ' ';
        }
        result += raw[i];
    }

    return result;
}

// 解密
std::string decode(const std::string& ciphertext, int a, int b) {
    if (!is_coprime(a, M)) {
        throw std::invalid_argument("a and m must be coprime.");
    }

    int a_inv = mod_inverse(a, M);

    std::string result;

    for (char c : ciphertext) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            int y = std::tolower(c) - 'a';
            int diff = (y - (b % M) + M) % M;
            int val = (static_cast<long long>(a_inv) * diff) % M;
            result += static_cast<char>('a' + val);
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            result += c;
        }
    }

    return result;
}

}  // namespace affine_cipher