// C++の関数 `power` は、`base` と `exponent` という2つの引数をとります。`exponent` のデフォルト値は2で、`power` は `base` を `exponent` 回累乗した結果を返します。
// baseを3、exponentを4としてこの関数を呼び出し、結果を出力してください。

#include <iostream>

int power(int base, int exponent){

    int result = base;

    for(int i = 1; i < exponent; i++){

        result *= base;

    }
    return result;
}

int main(){
    
    int result = power( 3, 4 );

    std::cout << result << std::endl;

    return 0;

}