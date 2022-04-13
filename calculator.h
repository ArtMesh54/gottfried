#include <vector>
#include <string>

class Calculator {
public:
    void AddMember(double num);
    void AddMember(char action);

    void AddEquation(std::string equation);
    int GetResult();

private: 
    enum Type { Variable, Action};

    struct Member {
        Type type;
        double number = 0;
        char action = '\0';
    };

private:
    bool IsOperator(char symbol);

private:
    std::vector<Member> eq_members;
};