
// https://projecteuler.net/problem=48

#include <iostream>

using namespace std;

int modp(int a, int b, int mod)
{
	if (a == 0)
	{
		return 0;
	}

	if (b == 0)
	{
		return 1;
	}

	long res = 1;

	if (b % 2 == 0)
	{
		int temp = modp(a, b / 2, mod);
		res = (temp * temp) % mod;
	}
	else
	{
		int temp = modp(a, b-1, mod);
		res = (a * temp) % mod;
	}

	cout << (int)res << endl;
	return (int)(res + mod) % mod;
}

long selfPowers(int a)
{
	long sum = 0;
	for (int i = 1; i <= a; i++)
	{
		sum += modp(i,i, 10000000000);
		cout << sum << endl;
	}

	return sum;

}

