#include "100.h"

// Fills an array with all perfect squares
void get_roots(long long* arr, long long n)
{
	for (long long i = 0; i < n; i++)
	{
		arr[i] = i * i;
	}
}

long long get_perfect_square(long long n)
{
	long long x = n;
	long long y = n%2 == 0 ? 0 : 1;
	long long sum = x + y;

	while (x>y)
	{
		if (sum%2!=0)
		{
			return 0;
		}
		x = (x + y) / 2;
		y = n / x;
	}

	return x;
}

long long arranged_probability()
{
	long long i = pow(10, 12);
	long long starting_red = pow(10, 8);
	long double intpart;
	for (long long j = 2; j < i*i; j++)
	{
		// need to implement a custom sqrt function
		float root = sqrtf(8 * j * j + 1);
		bool isInt = modf(root, &intpart) == 0;
		if (isInt)
		{
			long long total = (4 * j + 1 + root) / 2;
			unsigned long long blue = ((4 * j + 1 + (long long)root) / 2) - j;
			
			cout << "=====" << endl;
			cout << "Total: " << total << endl;
			//cout << "Root: " << root << endl;

			cout << "Red: " << j << endl;
			cout << "Blue: " << blue << endl;
			
			if (total > i)
			{
				return blue;
			}
		}
	}

	return 0;
}

long long arranged_probability_2()
{

	int size = pow(10, 7);
	long long* roots = new long long[size];
	get_roots(roots, size);

	for (int i = 2; i < size; i++)
	{
		if((roots[i]-1) % 8 == 0)
		{
			long long red = (roots[i] - 1) / 8;
			long long total = (4 * red + 1 + i) / 2;
			cout << "======" << endl;
			cout << "Total: " << total << endl;
			cout << "Red: " << red << endl;
			cout << "Red: " << total - red << endl;
			
			//long long root = sqrt((roots[i] - 1) / 8);
			
		}

	}

	return 0;
}