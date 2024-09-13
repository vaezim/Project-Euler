#include <iostream>
#include "utils.h"


const auto &primes = Utils::GeneratePrimes(500'000);
uint64_t GetNumDivisors(
    const std::vector<std::pair<uint64_t, uint64_t>> &divisors);

int main()
{
    uint64_t n{ 1 };
    uint64_t i{ 2 };
    while(true) {
        n += i++;
        const auto &divisors = Utils::GetDivisors(primes, n);
        if (GetNumDivisors(divisors) > 500) {
            break;
        }
    }
    std::cout << "Answer = " << n << std::endl;
}

uint64_t GetNumDivisors(
    const std::vector<std::pair<uint64_t, uint64_t>> &divisors)
{
    uint64_t ans{ 1 };
    for (const auto &item : divisors) {
        ans *= (item.second + 1);
    }
    return ans;
}