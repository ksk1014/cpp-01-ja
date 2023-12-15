#include <iostream>


int main(){

    int input {};

    std::cin >> input;

    if (input == 0) {
        std::cout << "value is zero" << std::endl;
    }
    else if (input > 0) {
        std::cout << "value is positive" << std::endl;
    }
    else {
        std::cout << "value is negative" << std::endl;
    };

};

