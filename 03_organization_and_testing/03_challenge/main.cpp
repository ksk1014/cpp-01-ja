#include <iostream>
#include "math_operations.h"
#include <stdexcept>

int main() {
    float num1, num2;
    char symbol;
    float out {0};

    std::cout << "Enter a calculation: ";
    std::cin >> num1 >> symbol >> num2;

    if(symbol == '+'){
        out = MathOps::addition(num1, num2);
    }else if(symbol == '-'){
        out = MathOps::subtraction(num1, num2);
    }else if(symbol == '*'){
        out = MathOps::multiplication(num1, num2);
    }else if(symbol == '/'){
        out = MathOps::division(num1, num2);
    }

    std::cout << "Result: " << out << std::endl;

    return 0

}