    
// Funkcja zwracająca wartość

#include <iostream>
using namespace std;

int kwadrat(int x)
{
    return x*x;
}

int main()
{
    //y=f(x)
    for(int i=0; i<5; i++)
        cout << kwadrat(kwadrat(i)) << endl;
    return 0;
}














