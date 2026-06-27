#include "two_bucket.h"

#include <queue>
#include <set>
#include <stdexcept>
#include <tuple>
#include <vector>

namespace two_bucket {

result measure(int bucket_one_cap, int bucket_two_cap, int goal,
               bucket_id start_bucket) {
    // 状态：(桶一水量, 桶二水量)
    using State = std::pair<int, int>;

    // 禁止状态：起始桶为空、另一个桶满，这个状态除了真正的起点外不能再出现
    State forbidden = (start_bucket == bucket_id::one)
                           ? State{0, bucket_two_cap}
                           : State{bucket_one_cap, 0};

    // 初始状态：先把起始桶装满
    State start_state = (start_bucket == bucket_id::one)
                             ? State{bucket_one_cap, 0}
                             : State{0, bucket_two_cap};

    std::queue<std::pair<State, int>> q;  // (状态, 到达这个状态用的操作数)
    std::set<State> visited;

    q.push({start_state, 1});
    visited.insert(start_state);
    visited.insert(forbidden);  // 禁止再次到达这个状态

    while (!q.empty()) {
        auto [state, moves] = q.front();
        q.pop();

        int b1 = state.first;
        int b2 = state.second;

        // 检查是否达到目标
        if (b1 == goal) {
            return result{moves, bucket_id::one, b2};
        }
        if (b2 == goal) {
            return result{moves, bucket_id::two, b1};
        }

        // 生成所有可能的下一个状态：装满1，装满2，倒空1，倒空2，1倒入2，2倒入1
        std::vector<State> next_states;
        next_states.push_back({bucket_one_cap, b2});  // 装满桶一
        next_states.push_back({b1, bucket_two_cap});  // 装满桶二
        next_states.push_back({0, b2});                // 倒空桶一
        next_states.push_back({b1, 0});                // 倒空桶二

        // 桶一倒入桶二
        {
            int pour = std::min(b1, bucket_two_cap - b2);
            next_states.push_back({b1 - pour, b2 + pour});
        }
        // 桶二倒入桶一
        {
            int pour = std::min(b2, bucket_one_cap - b1);
            next_states.push_back({b1 + pour, b2 - pour});
        }

        for (const auto& ns : next_states) {
            if (visited.find(ns) == visited.end()) {
                visited.insert(ns);
                q.push({ns, moves + 1});
            }
        }
    }

    throw std::runtime_error("无法达到目标水量");
}

}  // namespace two_bucket