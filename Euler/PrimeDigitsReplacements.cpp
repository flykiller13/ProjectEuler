
// https://projecteuler.net/problem=51

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isPrime(int a)
{
	for (int i = 0; i < a/2; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}

	return true;
}

// std::to_string(num).length()

// Returns the amount of prime replacements
int replacements(int arr [], int length)
{
	int counter = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (arr[j] == -1)
			{
				arr[j] = i;
			}
		}

		string buffer;

		for (int j = 0; j < length; j++)
		{
			buffer += arr[j];
		}

		cout << buffer << endl;

		int num = 0;
		stringstream stream(buffer);
		stream >> num;

		if (isPrime(num))
		{
			counter++;
		}
	}

	return counter;
}

// Driver code
void createArrays()
{
	const int arr_length = 5;
	int arr[arr_length] = {0};
	for (int i = 0; i < arr_length; i++)
	{

	}
}
