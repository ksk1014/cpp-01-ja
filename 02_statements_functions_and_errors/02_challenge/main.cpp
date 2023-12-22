#include <iostream>

int factorial(int n);

int main() {
  std::cout << "Factorial of 4 is " << factorial(4) << std::endl;
  return 0;
}

int factorial(int n) {

  int answer {};
  if (n == 0) {
    answer = 1;
    // std::cout << 1 << std::endl;
  } else {
    answer = n * factorial(n - 1);
    // std::cout << n * factorial(n - 1) << std::endl;
  }
  return answer;
}