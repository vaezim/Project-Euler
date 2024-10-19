#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "utils.h"


bool IsPanDigital(uint64_t p);

int main()
{
    std::cout << "Generating primes..." << std::endl;
    const auto &primes = Utils::GeneratePrimes(10'000'000);

    for (size_t i{ primes.size()-1 }; i >= 0; i--) {
        if (IsPanDigital(primes[i])) {
            std::cout << "Answer = " << primes[i] << std::endl;
            return 0;
        }
    }
}

bool IsPanDigital(uint64_t p)
{
    std::vector<int> digits;
    int numDigits{ 0 };
    while (p > 1) {
        int digit = p % 10;
        digits.push_back(digit);
        p /= 10;
        numDigits++;
    }
    if (digits.size() != numDigits) {
        return false;
    }
    std::sort(digits.begin(), digits.end());
    for (int i{ 1 }; i <= numDigits; i++) {
        if (digits[i-1] != i) {
            return false;
        }
    }
    return true;
}