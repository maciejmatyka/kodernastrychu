// #26 Operatory logiczne w C++
#include <iostream>
using namespace std;

int main()
{    
    bool warunek = true;
    
    if(!( !(warunek || (5<2))  ))
        cout << "Koder na strychu!\n";

    return 0;
}

