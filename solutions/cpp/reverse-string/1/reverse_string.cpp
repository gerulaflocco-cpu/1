#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {

std::string reverse_string(const std::string& text) {
    std::string result = text;
    std::reverse(result.begin(), result.end());
    return result    ;
}

}  // namespace reverse_string
