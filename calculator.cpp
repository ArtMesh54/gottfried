#include <vector>
#include <string>

#include "calculator.h"

// ---------------- public ----------------

void Calculator::AddMember(double num) {
    eq_members.push_back( {Type::Variable, num} );
}

void Calculator::AddMember(char action) {
    eq_members.push_back( {Type::Variable, 0, action} );
}

// only spaces allow
void Calculator::AddEquation(std::string equation) { 
    std::string number;
    for (char symbol : equation) {
        if (symbol >= '0' && symbol <= '9') {
            number.push_back(symbol);
        } else if (IsOperator(symbol)) {
            AddMember(std::stod(number));
            number.clear();
            AddMember(symbol);
        } else if (symbol == ' ') {
            continue;
        } else {
            break;
        }
    }
    AddMember(std::stod(number));
}

// only 2 member and 1 action
int Calculator::GetResult() {
    double second = eq_members.back().number;
    eq_members.pop_back();

    char action = eq_members.back().action;
    eq_members.pop_back();

    double first = eq_members.back().number;
    eq_members.pop_back();

    switch (action) {
        case '+':
            return first + second;
            break;
        case '-':
            return first - second;
            break;
        case '*':
            return first * second;
            break;
        case '/':
            return first / second;
            break;
        default:
            break;
    }

    return -1;
}

// ----------------- private -----------------

bool Calculator::IsOperator(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ) {
        return true;
    }
    return false;
}