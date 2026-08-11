#pragma once

namespace two_bucket {

enum class bucket_id { one, two };

struct result {
    int num_moves;
    bucket_id goal_bucket;
    int other_bucket_volume;
};

result measure(int bucket_one_cap, int bucket_two_cap, int goal,
               bucket_id start_bucket);

}  // namespace two_bucket