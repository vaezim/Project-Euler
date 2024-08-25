#include <vector>
#include <cstdint>

std::vector<uint64_t> GeneratePrimes(uint64_t nums)
{
    std::vector<uint64_t> primes;
    primes.reserve(nums);
    uint64_t i{ 2 };
    while (primes.size() < nums) {
        bool isPrime = true;
        for (const uint64_t &p : primes) {
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
        i++;
    }
    return primes;
}