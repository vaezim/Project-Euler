#include <cmath>
#include <vector>
#include <cstdint>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>


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
    GetPrimeFactors(const std::vector<uint64_t> &primes, uint64_t n)
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

std::vector<uint64_t> GetDivisors(uint64_t n)
{
    std::vector<uint64_t> divisors;
    auto sqrt = std::sqrt(n);
    for (uint64_t d{ 1 }; d < sqrt; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            divisors.push_back(n / d);
        }
    }
    uint64_t rounded_sqrt = static_cast<uint64_t>(std::floor(sqrt));
    if (n == rounded_sqrt * rounded_sqrt) {
        divisors.push_back(rounded_sqrt);
    }
    return divisors;
}

}