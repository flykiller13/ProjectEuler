
// https://projecteuler.net/problem=48

#include<iostream>

using namespace std;

int selfPowers(int a)
{
	int sum = 0;
	for (int i = 1; i <= a; i++)
	{
		sum += pow(i,i);
		cout << sum << endl;
	}

	return sum;
}

