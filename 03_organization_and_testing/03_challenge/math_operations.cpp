#include "math_operations.h"

namespace MathOps
{
    float addition(float num1, float num2){
        return num1 + num2;
        };

    float subtraction(float num1, float num2){
        return num1 - num2;
        }; 

    float multiplication(float num1, float num2){
        return num1 * num2;
        };

    float division(float num1, float num2){
        if(num2 == 0){
            throw;
        }
        return num1 / num2;
        };
    
} // namespace MathOps
