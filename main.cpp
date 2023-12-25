#include <iostream>
#include <string>

#include "calculator.h"
#include "gui.h"

int main()  {
    std::cout << "Hello, I am Gottfried \n";
    std::cout << "Enter your equation ";

    gui::OpenWindow();

    Calculator calc;
    std::string equation;

    int tryCount = 0;

    while (tryCount < 5) {
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
        ++tryCount;
    }
}