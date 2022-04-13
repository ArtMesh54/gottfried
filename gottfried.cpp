#include <iostream>
#include <string>

#include "calculator.h"

int main()  {
    std::cout << "Hello, I am Gottfried \n";
    std::cout << "Enter your equation ";

    Calculator calc;
    std::string equation;

    while (true) {
        std::getline(std::cin, equation);
        std::cout << equation << "\n= ";

        if (equation == "break") {
            calc.ClearMembers();
            continue;
        }

        if (!calc.AddEquation(equation)) {
            break;
        }
        equation.clear();
        std::cout << calc.GetResult();
        std::cout << std::endl;
    }
}
