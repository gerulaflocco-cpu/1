#if !defined(PARALLEL_LETTER_FREQUENCY_H)
#define PARALLEL_LETTER_FREQUENCY_H

#include <array>
#include <string_view>
#include <vector>

namespace parallel_letter_frequency {

class FrequencyMap {
   public:
    int& operator[](char c) { return counts_[static_cast<unsigned char>(c)]; }
    int operator[](char c) const { return counts_[static_cast<unsigned char>(c)]; }
    bool empty() const {
        for (int v : counts_) {
            if (v != 0) return false;
        }
        return true;
    }

   private:
    std::array<int, 256> counts_{};
};

FrequencyMap frequency(std::vector<std::string_view> const& texts);

}  // namespace parallel_letter_frequency

#endif