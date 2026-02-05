/*
//-----------------------Learning Basics--------------------
#include <string.h>
#include <iostream>
using namespace std;

void fun1(){
    cout<<"fun1\n";
}

void fun2(int x){
    cout<<"fun2 = "<< x << "\n";
}

string fun3(){
    return "fun3\n";
}

int main()
{
    // Case 1 : Without any argument
    void (*funPointer1)() = fun1;
    funPointer1();

    // Case 2 : With an int argument
    void (*funPointer2)(int) = fun2; // Type of argument should be passed while declaration
    funPointer2(10);

    // Case 3 : returning Value
    string (*funPointer3)() = fun3;
    cout << funPointer3();

    return 0;
}
*/

//----------------------Tricky Question---------------------------
#include <stdio.h>

void foo() { printf("Hello 1\n"); }
void bar() { printf("Hello 2\n"); }
void baz() { printf("Hello 3\n"); }

int main() {
    void (*funcs[3])() = {foo, bar, baz};  // void (*funcs[3])() = {foo, bar, baz}; 
                                           // funcs is an array of 3 function pointers. So, funcs[0] = foo, funcs[1] = bar, funcs[2] = baz.
    void (**p)() = funcs;

    (++p)[1](); 
    return 0;
}

/*

| Index | `funcs[index]` | Points to |
| ----- | -------------- | --------- |
| 0     | `funcs[0]`     | `foo()`   |
| 1     | `funcs[1]`     | `bar()`   |
| 2     | `funcs[2]`     | `baz()`   |


p originally → funcs[0]
After ++p → funcs[1]
p[1] → funcs[2] → baz

*/