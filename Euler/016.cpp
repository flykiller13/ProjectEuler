
// https://projecteuler.net/problem=16

#include <math.h>
#include <iostream>
#include <string>

using namespace std;

double power_sum(int b)
{
	const int size = 1000;
	string str = to_string((pow(2, b)));
	cout << "String :" << str << endl;
	int i= 0;
	int arr[size] = { 0 };
	while (str[i] != '.')
	{
		arr[i] = str[i] - '0';
		cout << arr[i];
		i++;
	}
	
	cout << endl;

	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}

	return sum;
}
