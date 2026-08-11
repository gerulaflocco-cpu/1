#include "parallel_letter_frequency.h"

#include <algorithm>
#include <cctype>
#include <thread>
#include <vector>

namespace parallel_letter_frequency {

namespace {

FrequencyMap count_range(std::vector<std::string_view> const& texts,
                          std::size_t begin, std::size_t end) {
    FrequencyMap local;
    for (std::size_t i = begin; i < end; ++i) {
        for (unsigned char c : texts[i]) {
            if (std::isalpha(c)) {
                local[static_cast<char>(std::tolower(c))]++;
            }
        }
    }
    return local;
}

}  // namespace

FrequencyMap frequency(std::vector<std::string_view> const& texts) {
    FrequencyMap result;
    if (texts.empty()) {
        return result;
    }

    std::size_t const num_threads = std::min(
        texts.size(),
        static_cast<std::size_t>(std::max(1u, std::thread::hardware_concurrency())));

    std::vector<FrequencyMap> partials(num_threads);
    std::vector<std::thread> threads;

    std::size_t const chunk = (texts.size() + num_threads - 1) / num_threads;

    for (std::size_t t = 0; t < num_threads; ++t) {
        std::size_t begin = t * chunk;
        std::size_t end = std::min(texts.size(), begin + chunk);
        if (begin >= end) break;
        threads.emplace_back([&texts, &partials, t, begin, end]() {
            partials[t] = count_range(texts, begin, end);
        });
    }

    for (auto& th : threads) {
        th.join();
    }

    for (auto const& p : partials) {
        for (int c = 'a'; c <= 'z'; ++c) {
            result[static_cast<char>(c)] += p[static_cast<char>(c)];
        }
    }

    return result;
}

}  // namespace parallel_letter_frequency