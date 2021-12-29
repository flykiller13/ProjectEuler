// 

#include "015.h"
#include <iostream>

using namespace std;
long long paths[100LL][100LL];

int lattice(int n)
{
	paths[1][1] = 2;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1)
			{
				if (j != 1)
				{
					paths[i][j] = paths[i][j - 1] + 1;
				}
			}
			else
			{
				if (j == 1)
				{
					paths[i][j] = paths[i - 1][j] + 1;
				}
				else
				{
					paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
				}
			}
			
			cout << "i: " << i << endl;
			cout << "j: " << j << endl;
			cout << paths[i][j] << endl;
		}

	}

	return 0;
}

int rec_lattice(int n1, int n2)
{
	cout << "( " << n1 << " , " << n2 << " ) " << endl;
	if (n1 == 1 || n2 ==1)
	{
		return n2;
	}

	if (n1 == 1 && n2 == 1)
	{
		return 2;
	}

	int x = rec_lattice(n1 - 1, n2);
	cout << x << endl;
	int y = rec_lattice(n1, n2 - 1);
	cout << y << endl;


	return x + y;
}