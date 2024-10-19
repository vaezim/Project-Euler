#include "utils.h"


bool IsAbundantNumber(int n);
std::vector<int> GenerateSumsOfAbundantNums(
    const std::vector<int> &abundants);

int main()
{
    std::vector<int> abundants;
    for (int i{ 1 }; i < 28123; i++) {
        if (IsAbundantNumber(i)) {
            abundants.push_back(i);
        }
    }
    const auto &sum_abundants = GenerateSumsOfAbundantNums(abundants);
    uint64_t sum{ 0 };
    for (uint64_t i{ 1 }; i < 28123; i++) {
        if (sum_abundants[i] == 0) {
            sum += i;
        }
    }
    std::cout << "Answer = " << sum << std::endl;
}

bool IsAbundantNumber(int n)
{
    const auto &divisors = Utils::GetDivisors(n);
    auto sum = std::accumulate(divisors.begin(), divisors.end(), 0);
    return (sum - n) > n; 
}

std::vector<int> GenerateSumsOfAbundantNums(
    const std::vector<int> &abundants)
{
    std::vector<int> sums(28123, 0);
    for (int i{ 0 }; i < abundants.size(); i++) {
        for (int j{ i }; j < abundants.size(); j++) {
            int S = abundants[i] + abundants[j];
            if (S < sums.size()) {
                sums[S] = 1;
            }
        }
    }
    return sums;
}