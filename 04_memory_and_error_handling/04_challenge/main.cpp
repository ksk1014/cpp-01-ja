#include <iostream>
#include <stdexcept>
#include <vector>

// コードを入力してください
int element_at(const std::vector<int> &numbers, int index){
    if(index >= 0 || index < numbers.size()){
        return numbers.at(index);
    }
    throw std::out_of_range("Please input valid range");
}
 
int main() {
    std::vector<int> numbers = {1, 3, 5, 7, 9};

    try{
        int result = 0;
        // std::cout << result << std::endl;

        result = element_at(numbers, 10);
        std::cout << result << std::endl;
    } catch(const std::out_of_range& msg) {
        std::cerr << "Error: " << msg.what() << std::endl;
    }

    return 0;
}