#include "045.h"

int fast()
{
	long long n = 144;
	double intpart;
	while (n < 1000000)
	{
		long long h = n * (2 * n - 1);
		if (modf(((1 + (sqrt(1 + 24 * h))) / 6), &intpart)==0)
		{
			cout << "Winner: " << h << endl;
			return 0;
		}
		n++;
	}
}

unsigned long long TPH()
{
	unsigned long long i = 144;

	while (i < 10000000)
	{
		unsigned long long H = i * (2*i - 1);
		unsigned long long j = i;
		while (j < i*2)
		{
			unsigned long long P = (j * (3 * j - 1)) / 2;
			
			if (H == P)
			{
				cout << "H=P for: " << P << endl;
				unsigned long long c = j;
				while (c < j * 2)
				{

					unsigned long long T = (c * (c + 1)) / 2;
					if (T == P)
					{
						cout << "Winner: " << T << endl;
						return 0;
					}
					c++;
				}
				
			}
			j++;
		}
		i++;

	}
	
	return 0;
}