#pragma once

#include <string>

namespace affine_cipher {

std::string encode(const std::string& plaintext, int a, int b);
std::string decode(const std::string& ciphertext, int a, int b);

}  // namespace affine_cipher