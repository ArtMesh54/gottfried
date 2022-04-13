#include <iostream>
#include <string>

#include "calculator.h"

int main()  {
    std::cout << "Hello, I am Gottfried \n";

    std::cout << "Enter your equation ";
    std::string equation;
    std::getline(std::cin, equation);
    std::cout << equation << '\n';

    std::cout << "\nYour result = ";
    Calculator calc;
    calc.AddEquation(equation);
    // calc.AddOperator(first);
    // calc.AddOperator(static_cast<int>(action));
    // calc.AddOperator(second);

    std::cout << calc.GetResult();
}