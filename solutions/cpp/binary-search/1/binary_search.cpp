#include "binary_search.h"
#include <stdexcept>
namespace binary_search {

std::size_t find(const std::vector<int>& data, int target) {
    if (data.empty()) {
        throw std::domain_error("value not in array");
        
    }
    std::size_t left = 0;
    std::size_t right = data.size() - 1;

    while (left <= right) {
        std::size_t mid = left + (right - left) / 2;

        if (data[mid] == target) {
            return mid;}
         else if (data[mid] < target) {
left = mid +1 ;}
        else {
                if (mid == 0) break;
            right = mid - 1;
        }
            }throw std::domain_error("value not in array");
        }
    
    }


  // namespace binary_search
