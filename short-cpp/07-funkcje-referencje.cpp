    
// Przekazywanie argumentów przez referencję (bez gwiazdek!)

#include <iostream>
using namespace std;

void zeruj( int &a)
{
    a=0;
}

int main()
{
    int zmienna = 4;
    zeruj( zmienna );
     cout << zmienna << endl;
    return 0;
}














