#include <iostream>

// Coin values array should be sorted
// https://projecteuler.net/problem=31

int combinations[1000] = {0};
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

int main() {

    // Coin sums driver code
    int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200};
    std::cout << coinSums(200, coins, 8) << std::endl;

    return 0;
}