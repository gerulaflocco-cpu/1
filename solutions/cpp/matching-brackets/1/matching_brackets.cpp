#include "matching_brackets.h"
    
#include <stack>
namespace matching_brackets {

bool check(const std::string& input) {
    std::stack<char> open_stacks;

    for (char c : input) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                open_stacks.push(c);
            break;
            case ')':
            if (open_stacks.empty() || open_stacks.top() != '(') {
                return false;
            }
            open_stacks.pop();
            break;
             case ']':
            if (open_stacks.empty() || open_stacks.top() != '[') {
                return false;
            }
            open_stacks.pop();
            break;
             case '}':
            if (open_stacks.empty() || open_stacks.top() != '{') {
                return false;
            }
            open_stacks.pop();
            break;    
            default:
                break;
        }
    }

    return open_stacks.empty();
}

} 
