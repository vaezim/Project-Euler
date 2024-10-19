#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


std::vector<std::vector<int>> grid;

int main()
{
    // Read file
    std::ifstream ifs;
    ifs.open("resources/0067_triangle.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        std::string num;
        std::stringstream ss(line);
        grid.push_back(std::vector<int>{});
        while (std::getline(ss, num, ' ')) {
            grid.back().push_back(std::stoi(num));
        }
    }

    // Bottom-up filling
    for (int i{ (int)grid.size()-2 }; i >= 0; i--) {
        for (int j{ 0 }; j < grid[i].size(); j++) {
            grid[i][j] += std::max(grid[i+1][j], grid[i+1][j+1]);
        }
    }
    std::cout << "Answer = " << grid[0][0] << std::endl;
}