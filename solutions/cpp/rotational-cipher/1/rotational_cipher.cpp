#include "rotational_cipher.h"

namespace rotational_cipher {

std::string rotate(const std::string& text, int shift) {
    std::string result = text;
    for (char& c : result) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            c = base + (c - base + shift) % 26;
        }
    }
    return result;
}

} // namespace rotational_cipher