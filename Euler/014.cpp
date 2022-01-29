#include "014.h"

long long chain_len(long long n)
{
	if (n == 1)
	{
		return 1;
	}

	if (n % 2 == 0)
	{
		return chain_len(n / 2) + 1;
	}

	return chain_len(3 * n + 1) + 1;
}

long long longest_chain(int n)
{
	long long* arr = new long long[n+1];
	arr[1] = 1;

	long long max = 0;

	for (long long i = 1; i <= n; i++)
	{
		arr[i] = chain_len(i);
		if (arr[i] > max)
		{
			max = arr[i];
			cout << "New max. Number: " << i << endl;
		}
	}

	delete[](arr);

	return max;
}

