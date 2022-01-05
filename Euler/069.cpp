
// https://projecteuler.net/problem=69
// https://cp-algorithms.com/algebra/phi-function.html

// The method introduced by Euclid for computing greatest common divisors is based on the
// fact that, given two positive integers a and b such that a > b,
// the common divisors of a and b are the same as the common divisors of a – b and b.

#include "069.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n)
{
	if (n == 2)
	{
		return true;
	}

	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int prime_power(int n)
{
	for (int i = 2; i * i<= n; i++)
	{
		if (is_prime((int)pow(n, i)))
		{
			return i;
		}
	}

	return 0;
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

int phi(int n)
{
	int counter = 0;
	if (is_prime(n))
	{
		return n - 1;
	}

	int power = prime_power(n);
	if (power > 0)
	{
		return (int)(pow(n, power) - pow(n, power - 1));
	}

	for (int i = 1; i <= n; i++)
	{
		if (relative_prime(i, n))
		{
			// cout << "Relative prime: " << i << endl;
			counter++;
		}
	}

	// cout << "Total Relative primes: " << counter << endl;

	return counter==0 ? -1 : counter;
}

double solve(int n)
{
	double maxIndex = 0;
	double maxRes = 0;
	double res = 0;
	for (int i = 2; i < n; i++)
	{
		double res = (double)i / (double)phi(i);
		//cout << "Checking: " << i << endl;

		//cout << "Res: " << res << endl;
		if (res > maxRes)
		{
			cout << "Changing: " << i << endl;

			maxRes = res;
			maxIndex = i;
		}
	}

	return maxIndex;
}
