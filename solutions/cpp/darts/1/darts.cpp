// darts.cpp
#include "darts.h"

namespace darts {

int score(float x, float y) {
    float dist = x * x + y * y; // 距离的平方

    if (dist <= 1.0f * 1.0f)   return 10; // 内圆 半径1
    if (dist <= 5.0f * 5.0f)   return 5;  // 中圆 半径5
    if (dist <= 10.0f * 10.0f) return 1;  // 外圆 半径10
    return 0;                              // 圆外
}

} // namespace darts