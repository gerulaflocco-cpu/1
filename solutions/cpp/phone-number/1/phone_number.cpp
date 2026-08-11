#include "phone_number.h"
#include <regex>
#include <stdexcept>

namespace phone_number {

phone_number::phone_number(const std::string& input) {
if (std::regex_search(input, std::regex("[a-zA-Z]")))
throw std::domain_error("letters not permitted");
if (std::regex_search(input, std::regex("[^0-9+\\-. ()]")))
throw std::domain_error("invalid punctuation");

std::string digits = std::regex_replace(input, std::regex("[^0-9]"), "");

if (digits.size() == 11) {
    if (digits.front() != '1')
        throw std::domain_error("11 digits must start with 1");
    digits.erase(0, 1);
}
if (digits.size() != 10){
    throw std::domain_error("incorrect number of digits");}
    if (digits[0] == '0') throw std::domain_error("area code cannot start with zero");
    if (digits[0] == '1') throw std::domain_error("area code cannot start with one");
    if (digits[3] == '0') throw std::domain_error("exchange code cannot start with zero");
    if (digits[3] == '1') throw std::domain_error("exchange code cannot start with one");

    number_ = std::move(digits);

    
}std::string phone_number::number() const { return number_; }}
  // namespace phone_number
