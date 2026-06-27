#include "sublist.h"

namespace sublist {

    List_comparison sublist(const std::vector<int>& list1, const std::vector<int>& list2) {
        // 1. 两个空列表
        if (list1.empty() && list2.empty()) {
            return List_comparison::equal;
        }

        // 2. list1 为空，list2 不为空 → list1 是 list2 的子列表
        if (list1.empty()) {
            return List_comparison::sublist;
        }

        // 3. list2 为空，list1 不为空 → list1 是 list2 的超列表
        if (list2.empty()) {
            return List_comparison::superlist;
        }

        size_t len1 = list1.size();
        size_t len2 = list2.size();

        // 4. 如果 list1 比 list2 长，交换角色判断
        if (len1 > len2) {
            List_comparison result = sublist(list2, list1);
            if (result == List_comparison::sublist) {
                return List_comparison::superlist;
            }
            if (result == List_comparison::superlist) {
                return List_comparison::sublist;
            }
            return result;
        }

        // 5. list1 长度 <= list2，检查 list1 是否是 list2 的子列表
        for (size_t i = 0; i <= len2 - len1; ++i) {
            bool is_match = true;
            for (size_t j = 0; j < len1; ++j) {
                if (list2[i + j] != list1[j]) {
                    is_match = false;
                    break;
                }
            }
            if (is_match) {
                return (len1 == len2) ? List_comparison::equal : List_comparison::sublist;
            }
        }

        return List_comparison::unequal;
    }

} // namespace sublist