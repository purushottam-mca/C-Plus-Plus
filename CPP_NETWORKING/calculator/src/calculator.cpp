#include "calculator.h"
#include <stdexcept>

double Calculator::add(double a, double b){
    return a+b;
}

double Calculator::sub(double a, double b){
    return a-b;
}

double Calculator::mult(double a, double b){
    return a*b;
}

double Calculator::div(double a, double b){
    if(b==0){
        throw std::invalid_argument("Division By Zero");
    }
    return a/b;
}