#include "053.h"

int binom()
{
	long long arr[101][101];
	long long max = 1000000;

	int c = 0;

	// Init array
	for (int i = 0; i < 101; i++)
	{
		arr[1][i] = i;
	}

	for (int n = 2; n <= 100; n++)
	{
		for (int r = 1; r <= n; r++)
		{
			if (n==r)
			{
				arr[n][r] = 1;
			}
			else
			{
				long long temp = arr[n - 1][r] * ((double)n / (n - r));

				if (temp > max)
				{
					cout << "BIG: "<< temp << endl;
					arr[n][r] = max + 1;
					cout << "BINOM: " << "(" << n << " " << r << ")" << endl;
					c++;
				}
				else
				{
					arr[n][r] = temp;
				}
			}

		}
	}

	return c;
}