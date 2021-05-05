// #18 Użycie <iomanip> do wypisywania float
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
    cout << setprecision(9) << 0.49457483;
    return 0;
}

