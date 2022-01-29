#include "028.h"

int spiral(int n)
{
	int size = n + 1;
	int* layers = new int[size];
	layers[1] = 1;
	int sum = 1;
	for (int i = 3; i <= n; i+=2)
	{
		int side_length = i - 1;
		sum += i * i + (i * i - (side_length)) + (i * i - 2*(side_length)) + (i * i - 3*(side_length));
	}

	delete[](layers);

	return sum;
}