#include <iostream>

// 👉 Formatowanie kodu bez tajemnic
// 1. Elementy programu C++
// 2. Podstawowe zasady: pętle, funkcje, nawiasy.
// 3. Czego nie robić
// 4. Co jest najważniejsze? 
// 5. Opcje Visuala C++ 2019

int main()
{
	for(int i=0; i<10; i++) 
	{
		if(i==8) 
		{
			std::cout << "Hello World!\n";
			
			for(int b=0; b<21; b++) 
			{
				std::cout << "b=" << b <<std::endl;
			}
		}
	}

	std::cout << "Juz po petli\n";
	
	int a=4;
	
	switch(a)
	{
		case 1:
			break;

		default:
			break;
	}
}

