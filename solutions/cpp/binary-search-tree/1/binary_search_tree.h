#pragma once
#include <memory>
#include <stack>

namespace binary_search_tree {

template <typename T>
class binary_tree {
public:
    explicit binary_tree(const T& value) : value_(value) {}

    const T& data() const { return value_; }

    const std::unique_ptr<binary_tree<T>>& left() const { return left_; }
    const std::unique_ptr<binary_tree<T>>& right() const { return right_; }

    void insert(const T& value) {
        if (value <= value_) {
            if (left_)
                left_->insert(value);
            else
                left_ = std::make_unique<binary_tree<T>>(value);
        } else {
            if (right_)
                right_->insert(value);
            else
                right_ = std::make_unique<binary_tree<T>>(value);
        }
    }

    struct iterator {
        using value_type        = T;
        using reference         = const T&;
        using pointer           = const T*;
        using difference_type   = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        iterator() = default;

        explicit iterator(const binary_tree<T>* root) {
            push_left(root);
        }

        reference operator*() const { return stack_.top()->value_; }
        pointer operator->() const  { return &stack_.top()->value_; }

        iterator& operator++() {
            const binary_tree<T>* node = stack_.top();
            stack_.pop();
            push_left(node->right_.get());
            return *this;
        }

        iterator operator++(int) {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& other) const { return stack_ == other.stack_; }
        bool operator!=(const iterator& other) const { return !(*this == other); }

    private:
        std::stack<const binary_tree<T>*> stack_;

        void push_left(const binary_tree<T>* node) {
            while (node) {
                stack_.push(node);
                node = node->left_.get();
            }
        }
    };

    iterator begin() const { return iterator(this); }
    iterator end()   const { return iterator(); }

private:
    T value_;
    std::unique_ptr<binary_tree<T>> left_;
    std::unique_ptr<binary_tree<T>> right_;
};

}  // namespace binary_search_tree