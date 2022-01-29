#include "010.h"

long long sum_of_primes()
{
	long long sum = 0;
	bool* primes = new bool[2000001];

	get_primes(2000000, primes);

	for (int i = 2; i < 2000000; i++)
	{
		if (primes[i])
		{
			//cout << "Sum: " << sum << endl;
			sum += i;
		}

	}

	delete[](primes);

	return sum;
}