#include "high_scores.h"
#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores_;
}

int HighScores::latest_score() {
    return scores_.back();
}

int HighScores::personal_best() {
    return *std::max_element(scores_.begin(), scores_.end());
}

std::vector<int> HighScores::top_three() {
    std::vector<int> sorted = scores_;  // 拷贝，不修改原始数据
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());
    
    int count = std::min(3, static_cast<int>(sorted.size()));
    return std::vector<int>(sorted.begin(), sorted.begin() + count);
}

}  // namespace arcade