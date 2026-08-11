#pragma once
#include <mutex>
#include <stdexcept>
namespace Bankaccount {
class Bankaccount {
    public:
    void open();
    void close();
    int balance() const;
    void deposit(int amount);
    void withdraw(int amount);

    private:
    mutable std::mutex mtx_;
    int balance_ = 0;
    bool is_open_ = false;
};  

}  // namespace Bankaccount
