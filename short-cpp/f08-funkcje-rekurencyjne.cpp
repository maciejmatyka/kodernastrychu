// Funkcje rekrencyjne na przykładzie sumy ciągu n, n-1, n-2, ..., 0
// Koder na strychu 2021 
// https://www.youtube.com/c/KodernaStrychu/

#include <iostream>
using namespace std;

int suma(int a)
{
    if(a==0) return 0;
    return a+suma(a-1);
}

int main()
{
   cout << suma(2) << endl;
   return 0;
}














