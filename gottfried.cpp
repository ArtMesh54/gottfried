#include <iostream>
#include "calculator.h"

int main()  {
    std::cout << "Hello, I am Gottfried \n";

    std::cout << "Enter first number ";
    int first = 0; 
    std::cin >> first;

    std::cout << "\nEnter action ";
    char action = '+';
    std::cin >> action;

    std::cout << "\nEnter second number ";
    int second = 0; 
    std::cin >> second;

    std::cout << "\nYour result = ";
    Calculator calc;
    calc.AddOperator(first);
    calc.AddOperator(static_cast<int>(action));
    calc.AddOperator(second);
    std::cout << calc.GetResult();
}