#include "grains.h"

namespace grains {

// TODO: add your solution here
uint64_t square(int n) {
    if (n < 1 || n > 64) {
        throw std::domain_error("square must be 1 and 64");
         
    
}return 1ULL << (n - 1);}

uint64_t total() {
    return UINT64_MAX;
}
}  // namespace grains
