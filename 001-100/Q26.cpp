#include <cmath>
#include <iostream>
#include <unordered_map>


unsigned GetCycleLength(int a, int b);

int main()
{
    unsigned max{ 0 };
    unsigned maxVal{ 0 };
    for (unsigned i{ 1 }; i < 1000; i++) {
        unsigned cycleLength = GetCycleLength(1, i);
        if (cycleLength > max) {
            max = cycleLength;
            maxVal = i;
        }
    }
    std::cout << "Answer = " << maxVal << std::endl;
}

unsigned GetCycleLength(int a, int b)
{
    int i{ 1 };
    std::unordered_map<unsigned, int> visited;
    while(true) {
        if (a == 0) {
            return 0;
        }
        while (a < b) a *= 10;
        a = a % b;
        auto itr = visited.find(a);
        if (itr != visited.end()) {
            return i - itr->second;
        }
        visited.emplace(a, i++);
    }
    return 0;
}