#include <vector>
#include <string>
#include <stack>
#include <iostream>

#include "calculator.h"

// ---------------- public ----------------

void Calculator::AddMember(double num) {
    eq_members.push_back( {Type::Variable, num} );
}

void Calculator::AddMember(char action) {
    eq_members.push_back( {Type::Action, 0, action} );
}

void Calculator::ClearMembers() {
    eq_members.clear();
}

bool Calculator::AddEquation(const std::wstring& equation) { 
    std::wstring rpn_equation = ConvertToRPN(equation);
  
    std::wstring member;
    bool is_current_number = false;
    
    for (char symbol : rpn_equation) {
        if (symbol >= '0' && symbol <= '9' || symbol == '.' || symbol == ',') {
            member.push_back(symbol);
            is_current_number = true;
        } else if (IsOperator(symbol)) {
            AddMember(symbol);
            is_current_number = false;
        } else if (symbol == ' ') {
            if (is_current_number) {
                AddMember(std::stod(member));
                member.clear();
                is_current_number = false;
            }
        } else {
            return false;
        }
    }

    return true;
}

double Calculator::GetResult() {
    std::string rpn;
    std::stack<double> operands;
    for (auto element : eq_members) {
        if (element.type == Calculator::Type::Variable) {
          auto num = element.number;
          operands.push(num);
        } else if (element.type == Calculator::Type::Action) {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            switch (element.action) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }  
    }

    return operands.top();
}

// ----------------- private -----------------

bool Calculator::IsOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int Calculator::OperatorPriority(char symbol) {
  switch (symbol) {
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
  }
}

std::wstring Calculator::ConvertToRPN(const std::wstring& equation) {
  std::stack<char> operators;
  std::wstring rpn_equation;

  for (char c : equation) {
    if (isdigit(c)) {
      rpn_equation += c;
    } else if (c == '(') {
      operators.push(c);
    } else if (c == ')') {
      while (!operators.empty() && operators.top() != '(') {
        rpn_equation += ' ';
        rpn_equation += operators.top();
        operators.pop();
      }
      operators.pop(); // Pop the '('
    } else if (IsOperator(c)) {
      while (!operators.empty() && OperatorPriority(operators.top()) >= OperatorPriority(c)) {
        rpn_equation += ' ';
        rpn_equation += operators.top();
        operators.pop();
      }
      operators.push(c);
      rpn_equation += ' '; // Add space to distinguish numbers
    }
  }

  // Append remaining operators
  while (!operators.empty()) {
    rpn_equation += ' ';
    rpn_equation += operators.top();
    operators.pop();
  }

  return rpn_equation;
}