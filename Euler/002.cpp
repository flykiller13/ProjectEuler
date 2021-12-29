#include <iostream>

using namespace std;

int even_fibonacci()
{
	int sum = 0;
	int t1 = 0, t2 = 1, nextNum = 0;
	nextNum = t1 + t2;
	while (nextNum <= 4000000)
	{
		if (nextNum % 2 == 0)
		{
			sum = sum + nextNum;
		}

		cout << nextNum << endl;

		t1 = t2;
		t2 = nextNum;
		nextNum = t1 + t2;

		
	}
	return sum;
}