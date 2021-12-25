
// https://projecteuler.net/problem=31

#include <iostream>

// Memory reservation for combinations array
int combinations[1000] = { 0 };

// Dynamic programming solution:
// (Coin values array should be sorted)
// coinSums returns the amount of different ways the "amount" param
// can be made up of the coin values given by the "coins" array.
int coinSums(int amount, int coins[], int num_of_coins)
{
    combinations[0] = 1;

    for (int i = 0; i < num_of_coins; i++)
    {
        for (int j = 1; j < 500; j++)
        {
            if (j >= coins[i])
            {
                combinations[j] += combinations[j - coins[i]];

            }
        }
    }

    return combinations[amount];
}

// Coin sums driver code
int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
std::cout << coinSums(200, coins, 8) << std::endl;