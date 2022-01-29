#include "006.h"

int solve(int n) 
{
	int sum_of_squares = 0, square_of_sums = 0;

	for (int i = 1; i <= n; i++)
	{
		sum_of_squares += i * i;
	}

	for (int i = 1; i <= n; i++)
	{
		square_of_sums += i;
	}
	square_of_sums = square_of_sums * square_of_sums;

	return abs(square_of_sums - sum_of_squares);
}