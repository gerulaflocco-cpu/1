#pragma once
#include <vector>

namespace arcade {

class HighScores {
public:
    HighScores(std::vector<int> scores) : scores_(scores) {}
    
    std::vector<int> list_scores();
    int latest_score();
    int personal_best();
    std::vector<int> top_three();

private:
    std::vector<int> scores_;
};

}  // namespace arcade