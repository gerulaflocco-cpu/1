#include "nth_prime.h"
#include <stdexcept>
namespace nth_prime {
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return false;
    }
    return true;
}

int nth(int n) {
    if  (n < 1) throw std::domain_error("n must be >= 1");

    int count = 0;
    int candidate = 1;

    while (count < n) {
        ++candidate;
        if (is_prime(candidate)) ++count;
    }
    return candidate;
}

}  // namespace nth_prime
