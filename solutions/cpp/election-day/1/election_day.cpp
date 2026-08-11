#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};
int vote_count(const ElectionResult& result) {
    return result.votes;
}

void increment_vote_count(ElectionResult& reslut, int votes) {
    reslut.votes += votes;
}

ElectionResult& determine_result(std::vector<ElectionResult>& resluts) {
    ElectionResult* winner = &resluts[0];

    for(ElectionResult& canadiate : resluts) {
        if (canadiate.votes > winner->votes){
            winner = &canadiate;
        }
    }
    
    winner->name = "President " + winner->name;
    return *winner;
}
}  // namespace election
