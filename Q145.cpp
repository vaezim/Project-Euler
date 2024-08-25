#include <iostream>


bool IsReversible(const uint32_t &n);

int main()
{
    uint32_t N{ 1'000'000'000 };
    int numReversibles{ 0 };
    for (uint32_t i{ 1 }; i < N; i++) {
        numReversibles += static_cast<int>(IsReversible(i));
        if (i % 100'000'000 == 0) {
            std::cout << (double)i / N * 100.0 << "% searched...\n";
        }
    }
    std::cout << "Number of reversible numbers less than 10^9 = " << numReversibles << std::endl;
}

bool IsReversible(const uint32_t &n)
{
    // Leading zeros are not allowed
    if (n % 10 == 0) {
        return false;
    }
    // Reverse of n
    uint32_t reverse{ 0 };
    uint32_t q{ n }, r;
    while (q != 0) {
        r = q % 10;
        q /= 10;
        reverse = reverse * 10 + r;
    }
    // Check digits of their sum
    uint32_t S = n + reverse;
    q = S;
    while (q != 0) {
        r = q % 10;
        if (r % 2 == 0) {
            return false;
        }
        q /= 10;
    }
    return true;
}