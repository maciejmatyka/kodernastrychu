//#31 liczby pseudolosowe (rand)
#include <iostream>
using namespace std;

int main()
{    
    // seed - 44- 43245- 43 -432
    // seed1 - 23 - 64 -35445 -5433
    // 0 - RAND_MAX
    srand(time(NULL));
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    return 0;
}

