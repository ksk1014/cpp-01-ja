#include <iostream>

int main() {
    int num1;
    int num2;
    int num3;
    float average;

    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    average = (num1 + num2 + num3) / 3.0f;

    std::cout << "Average is: " << average << std::endl;

    return 0;
}