#include "crypto_square.h"
#include <cmath>
namespace crypto_square {

cipher::cipher(const std::string& text) {
    for (char c :  text)
        if (std::isalnum((unsigned char)c))
        normalized_ += std::tolower((unsigned char)c);
    
}

std::string cipher::normalized_cipher_text() const {
    if (normalized_.empty()) return "";

    int len = (int)normalized_.size();
    int c  = (int)std::ceil(std::sqrt((double)len));
    int r = (int)std::ceil((double)len/ c);

    std::string padded = normalized_;
    padded.resize(r * c, ' ');

    std::string result;
    for (int col = 0; col < c;++col) {
        if (col > 0) result += ' ';
        for (int row = 0; row < r; ++row)
            result += padded[row * c + col];
     }
    return result;
}

}  // namespace crypto_square
