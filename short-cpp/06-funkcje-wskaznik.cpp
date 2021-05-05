    
// Przekazywanie argumentów przez wskaźnik

#include <iostream>
using namespace std;

void zeruj( int *a )
{
    (*a) = 0;
}

int main()
{
    int zmienna = 5;
    zeruj( &zmienna );
    cout << zmienna << endl;
    return 0;
}














