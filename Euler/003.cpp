// https://projecteuler.net/problem=3

#include <iostream>
#include "003.h"

using namespace std;

long long largest_prime_factor(long long n)
{
	long long max_factor = 0;

	for (long long i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n%i==0)
			{
				if (i > max_factor)
				{
					max_factor = i;
					cout << "New max factor: " << max_factor << endl;
				}
				n = n / i;
			}
		}

	}

	return max_factor;
	
}