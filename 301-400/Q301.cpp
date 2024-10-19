/**
 * X(a, b, c) = a XOR b XOR c
 * n XOR 2n XOR 3n = 0              =>
 * n XOR 2n = 3n                    =>
 * n XOR 2n = n + 2n                =>
 * n XOR (n << 1) = n + (n << 1)    =>
 * n should not have 2 consecutive '1's
 * D(N) = number of n < N that do not have 2 consecutive '1's
 * D(N) = 1 + D(N-1) + D(N-2)
 **/

#include <iostream>
#include <unordered_map>

std::unordered_map<int, uint64_t> memoization {
    { 2, 2 }, // D(2) = 2
    { 3, 4 }, // D(3) = 4  
};

uint64_t D(int n);

int main()
{
    uint64_t ans = 1 + D(30);
    std::cout << "Answer = " << ans << std::endl;
}

uint64_t D(int n)
{
    auto itr = memoization.find(n);
    if (itr != memoization.end()) {
        return itr->second;
    }
    uint64_t ans = 1 + D(n-1) + D(n-2);
    memoization[n] = ans;
    return ans;
}