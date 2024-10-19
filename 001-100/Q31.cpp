#include <vector>
#include <iostream>


std::vector<int> coins{ 1, 2, 5, 10, 20, 50, 100, 200 };

int main()
{
    std::vector<uint64_t> dp(201, 0);
    dp[0] = 1;
    for (int amount{ 1 }; amount < dp.size(); amount++) {
        for (const auto &coin : coins) {
            if (coin <= amount) {
                dp[amount] += dp[amount-coin];
            } else {
                break;
            }
        }
    }

    for (const auto &item : dp) {
        std::cout << item << ", ";
    }

    std::cout << "Answer = " << dp[200] << std::endl;
}