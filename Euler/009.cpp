// https://projecteuler.net/problem=9

#include <iostream>      
#include <math.h>

using namespace std;

int triplets()
{
	for (double i = 300; i < 400; i++)
	{
		for (double j = 1; j < 400; j++)
		{
			double c = sqrt(pow(i, 2) + pow(j, 2));
			cout << i << " , " << j << endl;
			cout << c << endl;

			if (i + j + c == 1000)
			{
				return i * j * c;
			}
		}

	}

	return 0;
}