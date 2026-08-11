#pragma once
#include <stdexcept>
#include <utility>
#include <vector>

namespace circular_buffer {

template <typename T>
class circular_buffer {
public:
    explicit circular_buffer(size_t capacity)
        : buf_(capacity), size_(0), head_(0), tail_(0) {}

    T read() {
        if (size_ == 0)
            throw std::domain_error("buffer is empty");
        T val = std::move(buf_[head_]);
        head_ = (head_ + 1) % buf_.size();
        --size_;
        return val;
    }

    void write(T val) {
        if (size_ == buf_.size())
            throw std::domain_error("buffer is full");
        buf_[tail_] = std::move(val);
        tail_ = (tail_ + 1) % buf_.size();
        ++size_;
    }

    void overwrite(T val) {
        if (size_ < buf_.size()) {
            write(std::move(val));
        } else {
            buf_[tail_] = std::move(val);
            tail_ = (tail_ + 1) % buf_.size();
            head_ = (head_ + 1) % buf_.size();
        }
    }

    void clear() {
        head_ = tail_ = 0;
        size_ = 0;
    }

private:
    std::vector<T> buf_;
    size_t size_;
    size_t head_;
    size_t tail_;
};

}  // namespace circular_buffer