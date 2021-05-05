// #14 prosta tablica dynamiczna (vector)

#include <iostream>
#include <vector>
using namespace std;

int main()
{    
    vector<int> liczby;
    liczby.push_back(5);
    liczby.push_back(-1);
    liczby.push_back(10);

    cout << liczby[2];
    return 0;
}

