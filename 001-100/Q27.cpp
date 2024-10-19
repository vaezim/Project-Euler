#include "utils.h"
#include <unordered_set>


const auto &primes = Utils::GeneratePrimes(10'000);

int GetNumPrimesGenerated(
    const std::unordered_set<uint64_t> &primeSet, int a, int b);

int main()
{
    std::unordered_set<uint64_t> primeSet;
    for (const auto &p : primes) {
        primeSet.emplace(p);
    }
    int max{ 0 };
    int maxProduct{ 0 };
    for (int a{ -999 }; a < 1000; a++) {
        for (int b{ -1000 }; b <= 1000; b++) {
            int numPrimes = GetNumPrimesGenerated(primeSet, a, b);
            if (numPrimes > max) {
                max = numPrimes;
                maxProduct = a * b;
            }
        }
    }
    std::cout << "Answer = " << maxProduct << std::endl;
}

int GetNumPrimesGenerated(
    const std::unordered_set<uint64_t> &primeSet, int a, int b)
{
    for (int n{ 0 }; n <= 1000; n++) {
        int num = n*n + a*n + b;
        if (primeSet.count(num) == 0) {
            return n;
        }
    }
    return -1;
}