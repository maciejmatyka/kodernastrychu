    
// Zmienne statyczne w funkcji - licznik

#include <iostream>
using namespace std;

void funkcja()
{
    static int n=0;
    n++;
    cout << "wywoales mnie " << n << endl;
}

int main()
{
    funkcja();
    funkcja();
    funkcja();

    return 0;
}














