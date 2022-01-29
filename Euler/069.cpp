
// https://projecteuler.net/problem=69
// https://cp-algorithms.com/algebra/phi-function.html

// The method introduced by Euclid for computing greatest common divisors is based on the
// fact that, given two positive integers a and b such that a > b,
// the common divisors of a and b are the same as the common divisors of a – b and b.

#include "069.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool* get_primes(int n, bool* arr)
{
	// Init array
	for (int i = 0; i <= n; i++)
	{
		arr[i] = true;
	}

	// "Gray out" multiples of primes
	int c = 0;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (arr[i])
		{
			c = 0;
			for (int j = i * i; j <= n; j = i*i + c * i)
			{
				arr[j] = false;
				c++;
			}
		}
	}

	// Return array where prime indexes are true
	return arr;
}

int * prime_factorize(int n, int * arr, bool * primes)
{

	for (int j = 0; j < n; j++)
	{
		arr[j] = 0;
	}

	int i = 2;

	while (n > 1 && i <= n)
	{
		while (n % i == 0)
		{
			arr[i]++;
			n = n / i;
		}

		i++;
	}

	return arr;
}

int euclid_gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return euclid_gcd(b, a % b);
}

bool relative_prime(int a, int b)
{
	return euclid_gcd(a, b) == 1;
}

int phi(int n, bool * primes, int * totients)
{
	int counter = 1;
	int* res = new int[n+1];
	prime_factorize(n, res, primes);
	
	// Go over primes that we got from factorization
	for (int i = 2; i < n; i++)
	{
		if (res[i] >= 1)
		{
			counter *= (int)(pow(i, res[i]) - pow(i, res[i] - 1));
			//cout << "Prime: " << i << endl;
			//cout << "Counter: " << n << endl;
		}
	}

	delete[](res);
	int relative_primes = counter == 1 ? n - 1 : counter;
	totients[n] = counter;
	//cout << "Relative primes for: " << n << " = " << relative_primes << endl;
	return relative_primes;
}

double solve(int n)
{
	double maxIndex = 0;
	double maxRes = 0;
	double res = 0;

	bool* primes = new bool[n + 1];
	get_primes(n, primes);
	
	int* totients = new int[n + 1];

	for (int i = 2; i < n; i++)
	{
		double phi_result = (double)phi(i, primes, totients);
		double res = (double)i / phi_result;
		//cout << "Checking: " << i << endl;

		//cout << "Res: " << res << endl;
		if (res > maxRes)
		{
			cout << "Changing: " << i << endl;

			maxRes = res;
			maxIndex = i;
		}
	}

	


	delete[](totients);

	return maxIndex;
}

// Solved using dynamic programming
int solve_dynamic(int n)
{
	int* arr = new int[n + 1];
	arr[1] = 1;

	bool* primes = new bool[n + 1];
	get_primes(n, primes);

	for (int i = 2; i <= n; i++)
	{
		if (primes[i])
		{
			arr[i] = i - 1;
		}
		else
		{
			int temp = i;
			int j = 2;
			int counter = 0;

			while (j*j <= temp)
			{
				if (temp % j == 0)
				{
					while (temp % j == 0)
					{
						temp = temp / j;
						counter++;
					}
					if (temp == 1)
					{
						arr[i] = (int)(pow(j, counter) - pow(j, counter - 1));
					}
					else
					{
						arr[i] = arr[(int)pow(j, counter)] * arr[temp];
					}

					break;
					
				}

				j++;
			}

		}
	}

	double maxIndex = 0;
	double maxRes = 0;
	double res = 0;

	for (int i = 2; i < n; i++)
	{
		double phi_result = (double)arr[i];
		double res = (double)i / phi_result;
		//cout << "Checking: " << i << endl;

		//cout << "Res: " << res << endl;
		if (res > maxRes)
		{
			cout << "Changing: " << i << endl;

			maxRes = res;
			maxIndex = i;
		}
	}

	delete[](primes);
	delete[](arr);

	return maxIndex;
}
