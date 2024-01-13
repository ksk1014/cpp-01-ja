#include <iostream>
#include <vector>

// コードを入力してください
std::vector<int> double_elements(const std::vector<int>& elements){

    std::vector<int> result;

    for(int n: elements){
        result.push_back(2 * n);
    }

    return result;

}


int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> doubled_numbers = double_elements(numbers);

    // コードを入力してくださいね
    for (int n : numbers) {
        std::cout << n << " ";
    }

    std::vector<int> result_list;
    result_list = double_elements(numbers);
    for(int n: result_list){
        std::cout << n << " ";
    }

    return 0;

}