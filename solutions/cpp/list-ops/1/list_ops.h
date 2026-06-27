#if !defined(LIST_OPS_H)
#define LIST_OPS_H

#include <vector>

namespace list_ops {

// append：把 rhs 的所有元素接到 lhs 末尾
template <typename T>
std::vector<T>& append(std::vector<T>& lhs, std::vector<T> const& rhs) {
    for (auto const& item : rhs) {
        lhs.push_back(item);
    }
    return lhs;
}

// concat：把多个列表合并成一个扁平列表
template <typename T>
std::vector<T> concat(std::vector<std::vector<T>> const& lists) {
    std::vector<T> result;
    for (auto const& list : lists) {
        for (auto const& item : list) {
            result.push_back(item);
        }
    }
    return result;
}

// filter：只保留满足谓词的元素
template <typename T, typename F>
std::vector<T> filter(std::vector<T> const& input, F predicate) {
    std::vector<T> result;
    for (auto const& item : input) {
        if (predicate(item)) {
            result.push_back(item);
        }
    }
    return result;
}

// length：返回元素个数
template <typename T>
size_t length(std::vector<T> const& input) {
    size_t count = 0;
    for (auto const& item : input) {
        (void)item;
        ++count;
    }
    return count;
}

// map：对每个元素应用函数，返回新列表
template <typename T, typename F>
auto map(std::vector<T> const& input, F func)
    -> std::vector<decltype(func(input.front()))> {
    std::vector<decltype(func(input.front()))> result;
    for (auto const& item : input) {
        result.push_back(func(item));
    }
    return result;
}

// foldl：从左往右折叠，func(累加器, 元素)
template <typename T, typename A, typename F>
A foldl(std::vector<T> const& input, A init, F func) {
    A acc = init;
    for (auto const& item : input) {
        acc = func(acc, item);
    }
    return acc;
}

// foldr：从右往左折叠，func(累加器, 元素)
template <typename T, typename A, typename F>
A foldr(std::vector<T> const& input, A init, F func) {
    A acc = init;
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        acc = func(acc, *it);
    }
    return acc;
}

// reverse：返回顺序反转的列表
template <typename T>
std::vector<T> reverse(std::vector<T> const& input) {
    std::vector<T> result;
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        result.push_back(*it);
    }
    return result;
}

}  // namespace list_ops

#endif