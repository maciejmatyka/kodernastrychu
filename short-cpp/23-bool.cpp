// #23 Zmienna bool
#include <iostream>
using namespace std;

bool czyprawda()
{
    return false;
}

int main()
{   
    bool warunek = true;

    if( czyprawda() )
        cout << "Koder na strychu!\n";

    return 0;
}

