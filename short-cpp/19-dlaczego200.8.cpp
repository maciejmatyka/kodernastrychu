// #19 Dlaczego 200 + 0.8 > 200.8 w C++? 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    float a = 200.0;
    float b = 0.8;
    cout << setprecision(15) << a+b;
    return 0;
}

