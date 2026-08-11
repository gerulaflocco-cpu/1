#include "atbash_cipher.h"
#include <cctype>

namespace atbash_cipher {

static char   encode_char(char c) {
    if (std::isalpha(c)) {
        return 'z' - (std::tolower(c) - 'a');
    }
    if (std::isdigit(c)) {
        return c;
    }
    return 0;
}
    std::string encode(const std::string& text) {
        std::string result;
        int count = 0;
        for (char c : text) {
            char encoded = encode_char(c);
            if (encoded) {
                    if (count > 0 && count % 5 == 0) {
                    result += ' ';
                    
                }
                result += encoded;
                ++count;
            }
        }
        return result;
    }
    std::string decode(const std::string& text) {
        std::string result;
         for (char c : text) {
            char decoded = encode_char(c);
            if (decoded) {
                    result += decoded;
    }}
    return result;}

}  // namespace atbash_cipher
