#include "secret_handshake.h"

namespace secret_handshake {

std::vector<std::string> commands(int n){
    std::vector<std::string> result;

    if ( n & 1) result.push_back("wink");
    if ( n & 2) result.push_back("double blink");
    if ( n & 4) result.push_back("close your eyes");
    if ( n & 8) result.push_back("jump");
    if ( n & 16) std::reverse(result.begin(), result.end());

    return result;
}

}  // namespace secret_handshake
