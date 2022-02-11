
// https://projecteuler.net/problem=59

#include "059.h"

using namespace std;

bool valid_char(char c)
{
	return (c >= 32 && c <= 90) || (c >= 97 && c <= 122);
}

const int encrypted_size = 4000;
int encrypted[encrypted_size] = {};
int ascii_sum(string p)
{
	string delimiter = ",";
	string s;
	for (int c1 = 97; c1 <= 122; c1++)
	{
		for (int c2 = 97; c2 <= 122; c2++)
		{
			for (int c3 = 97; c3 <= 122; c3++)
			{
				s = p;
				string temp = "";
				int arr[3] = { c1,c2,c3 };
				for (int i = 0; i < encrypted_size; i++)
				{
					
					if (p.length() > 0)
					{
						
						char key = arr[i % 3];
						// cout << "Current check: " << stoi(s.substr(0, s.find(delimiter))) << endl;
						encrypted[i] = stoi(s.substr(0, s.find(delimiter))) ^ key;
						s.erase(0, s.find(delimiter) + delimiter.length());
						//char c = '0' + encrypted[i];
						char c =  encrypted[i];
						
						if (valid_char(c))
						{
							//cout << c ;
							temp += c;
						}
						else
						{
							break;
						}
						
						
					}

				}
				//cout << endl;

				if (temp.length() <= p.length())
				{
					cout << "Key: " << (char)arr[0] << (char)arr[1] << (char)arr[2] << endl;
					cout << temp << endl;
				}

			}
		}

	}

	return 0;
}

long long solve(string p)
{
	string s = p;
	string temp = "";
	int arr[3] = { 101,120,112 };
	string delimiter = ",";
	long long sum = 0;

	for (int i = 0; i < encrypted_size; i++)
	{

		if (s.length() > 0)
		{
			cout << s << endl;
			char key = arr[i % 3];

			// ^ is bitwise XOR
			if (s.length() == 2)
			{
				encrypted[i] = stoi(s) ^ key;
				s.erase(0, s.length());
			}
			else 
			{
				encrypted[i] = stoi(s.substr(0, s.find(delimiter))) ^ key;
				s.erase(0, s.find(delimiter) + delimiter.length());
			}

			char c = encrypted[i];

			temp += c;
			sum = sum + (long long)c;
			cout << "Char: " << (long long)c << endl;
			cout << "Sum: " << sum << endl;

		}
	}

	if (temp.length() <= p.length())
	{
		cout << "Key: " << (char)arr[0] << (char)arr[1] << (char)arr[2] << endl;
		cout << temp << endl;
	}

	return sum;
}