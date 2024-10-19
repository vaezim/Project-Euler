#include <cmath>
#include <iostream>
#include "utils.h"


int main()
{
    const auto &primes = Utils::GeneratePrimes(1000);
    int odd{ 3 };
    while (true) {
        bool isGoldbach = false;
        for (const auto &p : primes) {
            if (p > odd) {
                break;
            }
            int doubleSquare = odd - p;
            if (doubleSquare % 2 == 1) {
                continue;
            }
            doubleSquare /= 2;
            int sqrt = static_cast<int>(std::floor(std::sqrt(doubleSquare)));
            if (sqrt * sqrt == doubleSquare) {
                isGoldbach = true;
                break;
            }
        }
        if (!isGoldbach) {
            std::cout << "Found a non-Goldbach odd composite number: " << odd << std::endl;
            return 0;
        }
        odd += 2;
    }
}