#include <iostream>


int main()
{
    uint64_t sum{ 1 };
    int a{ 1 };
    for (int i{ 3 }; i <= 1001; i += 2) {
        for (int j{ 0 }; j < 4; j++) {
            a += (i-1);
            sum += a;
        }
    }
    std::cout << "Answer = " << sum << std::endl;
}