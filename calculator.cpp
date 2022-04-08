#include <vector>
#include "calculator.h"

void Calculator::AddOperator(int oper) {
    operators.push_back(oper);
}

int Calculator::GetResult() {
    // only 2 member and 1 action
    int first = operators.back();
    operators.pop_back();

    char action = static_cast<char>(operators.back());
    operators.pop_back();

    int second = operators.back();
    operators.pop_back();

    switch (action) {
        case '+':
            return first + second;
            break;
    
        default:
            break;
    }

    return -1;
}