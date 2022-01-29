#include "007.h"

int prime_index(int n, bool *primes)
{
	// Init array
	for (int i = 0; i <= n*n; i++)
	{
		primes[i] = true;
	}

	// Gray out multiples
	int c = 0;
	for (int i = 2; i < n; i++)
	{
		if (primes[i])
		{
			c = 0;
			for (int j = i * i; j <= n*n; j = i * i + c * i)
			{
				primes[j] = false;
				c++;
			}
		}
	}

	int counter = 0;

	for (int i = 2; i < n*n; i++)
	{
		if (primes[i])
		{
			counter++;
			if (counter == n)
			{
				
				return i;
			}
			
		}

	}

	return 0;
}