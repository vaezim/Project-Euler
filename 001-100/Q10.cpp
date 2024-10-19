#include <iostream>
#include "utils.h"


int main()
{
    const auto &primes = Utils::GeneratePrimes(150'000);
    uint64_t sum{ 0 };
    for (const auto &p : primes) {
        if (p > 2'000'000) {
            break;
        }
        sum += p;
    }
    std::cout << "Answer = " << sum << std::endl;
}