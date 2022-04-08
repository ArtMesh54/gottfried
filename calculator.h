#include <vector>

class Calculator {
public:
    void AddOperator(int oper);
    int GetResult();

private:
    std::vector<int> operators;
};