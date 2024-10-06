#pragma once

#include <vector>
#include <string>

class Calculator {
public:
    void AddMember(double num);
    void AddMember(char action);
    void ClearMembers();

    bool AddEquation(const std::wstring& equation);
    double GetResult();

private: 
    enum Type { Variable, Action};

    struct Member {
        Type type;
        double number = 0;
        char action = '\0';
    };

private:
    bool IsOperator(char symbol);
    int OperatorPriority(char symbol);
    std::wstring ConvertToRPN(const std::wstring& equation);

private:
    std::vector<Member> eq_members;
};