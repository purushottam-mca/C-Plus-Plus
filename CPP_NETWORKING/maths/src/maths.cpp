#include <iostream>
#include "maths.h"

namespace MathFunctions{
    double cube(double x){
        return x*x*x;
    }

    double square(double x){
        return x*x;
    }

    double power(double base, double exponent){
        double result=1;
        for(int cnt=1; cnt <= exponent; cnt++){
            result *= base;
        }
        return result;
    }
}
