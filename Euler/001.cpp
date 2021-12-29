// https://projecteuler.net/problem=1
#include <iostream>
#include "001.h"

using namespace std;

long find_sum()
{
	int divisors[2] = { 3, 5 };
	long sum = 0;
	for (int i = 1; i < 1000; i++)
	{
		for (int j = 0; j < 2; j++)
		{	
			if (i % divisors[j] == 0)
			{
				sum = sum + i;
				cout << i << endl;
				break;
			}
		}
	}

	return sum;
}