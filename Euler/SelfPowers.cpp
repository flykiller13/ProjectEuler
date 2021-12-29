
// https://projecteuler.net/problem=48

#include <iostream>

using namespace std;

// Modular exponentiation - doesn't work for large numbers...
long long modp(long long a, long long b, long long mod)
{
	if (a == 0)
	{
		return 0;
	}

	if (b == 0)
	{
		return 1;
	}

	long long res = 0;
	

	if (b % 2 == 0)
	{
		long long temp = modp(a, b / 2, mod);
		res = (temp * temp);
		res = res % mod;
	}
	else
	{
		long long temp = modp(a, b-1, mod);
		res = (a * temp) % mod;
	}

	//cout << "Checking: " << a << "^" << b << endl;
	return res < 0 ? (res + mod) % mod : res;
}

long long modulo = 10000000000LL;

long long selfPowers(long long a)
{
	unsigned long long res = 0ULL, temp;
	int pow;

	for (int i = 1; i < a; i++)
	{
		pow = 1;
		temp = 1;
		while (pow <= i)
		{
			temp = (temp * i) % modulo;
			pow++;
		}

		res = (res + temp) % modulo;
	}

	return res;

}

