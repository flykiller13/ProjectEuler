#include "058.h"

long long spiral_primes()
{
	long long size = 100000;
	long long* layers = new long long[size+1];
	bool* primes = new bool[size*size+1];
	get_primes(size*size, primes);
	layers[1] = 0;
	double ratio = 0.1;
	for (long long i = 3; i < size; i += 2)
	{
		long long side_length = i;
		if (i * i - (side_length) > size * size + 1)
		{
			cout << "OUT OF BOUNDS" << endl;
			break;
		}
		long long corner3 = long long(primes[i * i - 3 * (side_length-1)]);
		//cout << "Corner 1: " << long long(primes[i * i - (side_length)]) << endl;
		//cout << "Corner 2: " << long long(primes[i * i - 2 * (side_length-1)]) << endl;
		//cout << "Corner 3: " << i * i - 2 * (side_length) << endl;
		long long temp = layers[i - 2] + long long(primes[i * i - (side_length-1)]) + long long(primes[i * i - 2 * (side_length-1)]) + long long(primes[i * i - 3 * (side_length-1)]);
		layers[i] = temp;
		long long total_diagonal = (((long long)i * 2) - 1);
		cout << "primes in this layer: " << temp << endl;
		double new_ratio = (double)temp / total_diagonal;
		if (new_ratio < ratio)
		{
				cout << "Winner! " << side_length << endl;
				break;
			
		}
	}

	delete[](layers);
	delete[](primes);

	return ratio;
}