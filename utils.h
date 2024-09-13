#include <cmath>
#include <vector>
#include <cstdint>
#include <utility>


namespace Utils {

std::vector<uint64_t> GeneratePrimes(uint64_t nums)
{
    std::vector<uint64_t> primes;
    primes.reserve(nums);
    uint64_t i{ 2 };
    while (primes.size() < nums) {
        bool isPrime = true;
        for (const uint64_t &p : primes) {
            if (p > std::sqrt(i)) {
                break;
            }
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

std::vector<std::pair<uint64_t, uint64_t>>
    GetDivisors(const std::vector<uint64_t> &primes, uint64_t n)
{
    std::vector<std::pair<uint64_t, uint64_t>> divisors;
    for (const auto &p : primes) {
        uint64_t power{ 0 };
        while (n % p == 0) {
            n /= p;
            power++;
        }
        if (power > 0) {
            divisors.emplace_back(p, power);
        }
        if (n == 1) {
            break;
        }
    }
    return divisors;
}

}