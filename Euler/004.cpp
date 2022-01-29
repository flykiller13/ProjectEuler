// https://projecteuler.net/problem=4

#include <iostream>
#include "004.h"
#include <string>

using namespace std;

int largest_palindrome()
{
	int max = 0;

	for (int i = 100; i < 1000; i++)
	{
		for (int j = i; j < 1000; j++)
		{
			int res = i * j;
			string num1 = to_string(res / 1000);
			string num2 = to_string(1000 + (res % 1000));
			//cout << "Num1: " << num1 << endl;
			//cout << "Num2: " << num2 << endl;
			if (num1.size() == 3)
			{
				// 543 345
				if (num1[0] == num2[3] && 
						num1[1] == num2[2] &&
							num1[2] == num2[1])
				{
					if (res > max)
					{
						max = res;
						cout << "New max: " << max << endl;
					}
				}

			}
		}

	}

	return max;
}