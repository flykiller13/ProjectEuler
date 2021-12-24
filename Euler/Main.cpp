#include <iostream>

// Coin values array should be sorted
int coinSums(int sum, int coinValues[] )
{
    int arraySize = sum;
    int count;
    int amountsArr[arraySize];
    
    for (int i = 0; i < sizeof(coinValues); i++)
    {
        int division = sum / coinValues[i];
    }
}

int main() {
    std::cout << "Hello World!";
    return 0;
}