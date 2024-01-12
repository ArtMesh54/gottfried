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

void Calculator::ClearMembers() {
    eq_members.clear();
}

// only spaces allowed
bool Calculator::AddEquation(std::wstring equation) { 
    std::wstring number;
    for (char symbol : equation) {
        if (symbol >= '0' && symbol <= '9' || symbol == '.' || symbol == ',') {
            number.push_back(symbol);

        } else if (IsOperator(symbol)) {
            if (!number.empty()) {
                AddMember(std::stod(number));
                number.clear();
            }
                       
            AddMember(symbol);

        } else if (symbol == ' ') {
            continue;
        } else {
            return false;
        }
    }
    AddMember(std::stod(number));
    return true;
}

// only 2 member and 1 action
double Calculator::GetResult() {
    double second = eq_members.back().number;
    eq_members.pop_back();

    char action = eq_members.back().action;
    eq_members.pop_back();

    double first = eq_members.back().number;
    eq_members.pop_back();

    double result = 0;

    switch (action) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            result = first / second;
            break;
        default:
            return -1;
    }

    AddMember(result);
    return result;
}

// ----------------- private -----------------

bool Calculator::IsOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}