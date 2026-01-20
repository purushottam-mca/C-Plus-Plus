#include <iostream>
#include "calculator.h"
#include "maths.h"

int main()
{
    std::cout<< "Calculator Application" << std::endl;
    Calculator calc;

    double num1, num2;
    char opt;

    std::cout<< "Enter first number : ";
    std::cin>>num1;

    std::cout<< "Enter an operator (+, -, *, /) : ";
    std::cin>>opt;

    std::cout<< "Enter second number : ";
    std::cin>>num2;

    try
    {
        switch (opt)
        {
            case '+':
                std::cout<<"Sum = "<<calc.add(num1,num2)<<std::endl;
                break;
            case '-':
                std::cout<<"Subtract = "<<calc.sub(num1,num2)<<std::endl;
                break;
            case '*':
                std::cout<<"Multiply = "<<calc.mult(num1,num2)<<std::endl;
                break;
            case '/':
                std::cout<<"Divide = "<<calc.div(num1,num2)<<std::endl;
                break;
            default:
                std::cout<<"Invalid Operator !" << std::endl;
                return 1;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<MathFunctions::power(8,3)<<std::endl;
    std::cout<<MathFunctions::cube(4)<<std::endl;

    return 0;
}