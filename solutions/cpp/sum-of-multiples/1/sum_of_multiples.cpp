#include "sum_of_multiples.h"
#include <unordered_set>
namespace sum_of_multiples {

int to(std::vector<int> bases, int level) {
    std::unordered_set<int> multiples;

    for (int base : bases) {
        if (base == 0) continue;
        for (int m = base; m < level;m += base ) {
            multiples.insert(m);
        }
    }

    int sum = 0;
    for (int n : multiples) sum += n;
    return sum;
}
}  
