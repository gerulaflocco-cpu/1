#include "eliuds_eggs.h"

namespace chicken_coop {

int positions_to_quantity(int display_value) {
    int count = 0;
    while (display_value > 0) {
        count += display_value & 1;  // 检查最低位是否为1
        display_value >>= 1;         // 右移一位
    }
    return count;
}

}  // namespace chicken_coop