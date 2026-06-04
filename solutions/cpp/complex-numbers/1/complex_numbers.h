#pragma once
#include <cmath>

namespace complex_numbers {

class Complex {
private:
    double r;  // 实部
    double i;  // 虚部

public:
    // 构造函数
    Complex(double real, double imag) : r(real), i(imag) {}

    // 获取实部和虚部
    double real() const { return r; }
    double imag() const { return i; }

    // 绝对值 |z| = sqrt(a^2 + b^2)
    double abs() const { return std::sqrt(r*r + i*i); }

    // 共轭 zc = a - b*i
    Complex conj() const { return {r, -i}; }

    // e^(a+bi) = e^a * (cos(b) + i*sin(b))
    Complex exp() const {
        double ea = std::exp(r);
        return {ea * std::cos(i), ea * std::sin(i)};
    }

    // 复数 + 复数
    Complex operator+(const Complex& o) const { return {r+o.r, i+o.i}; }

    // 复数 - 复数
    Complex operator-(const Complex& o) const { return {r-o.r, i-o.i}; }

    // 复数 * 复数：(ac - bd) + (bc + ad)i
    Complex operator*(const Complex& o) const {
        return {r*o.r - i*o.i, i*o.r + r*o.i};
    }

    // 复数 / 复数：(ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
    Complex operator/(const Complex& o) const {
        double denom = o.r*o.r + o.i*o.i;
        return {(r*o.r + i*o.i)/denom, (i*o.r - r*o.i)/denom};
    }

    // 复数 +/-/*/÷ 实数
    Complex operator+(double d) const { return {r+d, i}; }
    Complex operator-(double d) const { return {r-d, i}; }
    Complex operator*(double d) const { return {r*d, i*d}; }
    Complex operator/(double d) const { return {r/d, i/d}; }
};

// 实数 +/-/*/÷ 复数（全局运算符）
inline Complex operator+(double d, const Complex& c) { return c + d; }
inline Complex operator-(double d, const Complex& c) { return Complex{d, 0.0} - c; }
inline Complex operator*(double d, const Complex& c) { return c * d; }
inline Complex operator/(double d, const Complex& c) { return Complex{d, 0.0} / c; }

}  // namespace complex_numbers