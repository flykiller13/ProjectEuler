#include "041.h"

int pandigit_primes()
{
	bool* primes = new bool[1000000000];
	get_primes(1000000000, primes);

	for (int i = 10000000; i < 1000000000; i++)
	{
		if (primes[i])
		{
			cout << i << endl;
		}
	}

	return 0;
}