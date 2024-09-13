#include <queue>
#include <cmath>
#include <iostream>
#include "utils.h"


int main()
{
    uint64_t Y = 500500;
    uint64_t m = 500500507;
    const auto &primes = Utils::GeneratePrimes(600'000); // > Y

    std::priority_queue<uint64_t,
        std::vector<uint64_t>, std::greater<uint64_t>> queue;
    for (const uint64_t &p : primes) {
        queue.emplace(p);
    }

    uint64_t ans{ 1 };
    for (int i{ 0 }; i < Y; i++) {
        uint64_t n = queue.top();
        queue.pop();
        if (n < std::pow(2,31)) {
            queue.emplace(n*n);
        }
        ans = (ans * n) % m;
    }
    std::cout << "Answer = " << ans << std::endl;
}