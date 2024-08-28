#include <cmath>
#include <vector>
#include <cstdint>
#include <iostream>


struct Point {
    uint64_t x;
    uint64_t y;
};
using Grid = std::vector<std::vector<std::vector<Point>>>;

uint64_t m = 50515093;
uint64_t s0 = 290797;
uint64_t s1 = static_cast<uint64_t>(std::pow(s0, 2)) % m;
uint64_t k = 2'000'000; // Number of points
uint64_t num_segments = 100;
double min_distance = std::pow(10, 12);

void AddPoint(Grid &grid);
double Distance(const Point &p1, const Point &p2);
void GetClosestDistanceFromGrid(const Grid &grid);
void GetClosestDistanceFromList(const std::vector<Point> &points);

int main()
{
    // Create grid
    Grid grid;
    for (unsigned i{ 0 }; i < num_segments; i++) {
        grid.emplace_back(std::vector<std::vector<Point>> {});
        for (unsigned j{ 0 }; j < num_segments; j++) {
            grid.back().emplace_back(std::vector<Point> {});
        }
    }
    // Create points
    for (uint64_t i{ 0 }; i < k; i++) {
        AddPoint(grid);
    }
    // Get closest distance
    GetClosestDistanceFromGrid(grid);
    std::cout << "Min distance = " << min_distance << std::endl;
}

void AddPoint(Grid &grid)
{
    Point p { s0, s1 };
    grid[static_cast<size_t>(std::floor((double)s0 * num_segments / m))]
        [static_cast<size_t>(std::floor((double)s1 * num_segments / m))].emplace_back(p);
    s0 = static_cast<uint64_t>(std::pow(s1, 2)) % m;
    s1 = static_cast<uint64_t>(std::pow(s0, 2)) % m;
}

double Distance(const Point &p1, const Point &p2)
{
    return std::sqrt(
        std::pow((double)p1.x - (double)p2.x, 2) +
        std::pow((double)p1.y - (double)p2.y, 2)
    );
}

void GetClosestDistanceFromGrid(const Grid &grid)
{
    for (unsigned i{ 0 }; i < grid.size(); i++) {
        for (unsigned j{ 0 }; j < grid[i].size(); j++) {
            GetClosestDistanceFromList(grid[i][j]);
        }
        std::cout << "Searched " << (double)(i+1) / num_segments * 100 << "%" << std::endl;
    }
}

void GetClosestDistanceFromList(const std::vector<Point> &points)
{
    for (unsigned i{ 0 }; i < points.size(); i++) {
        for (unsigned j{ i+1 }; j < points.size(); j++) {
            double d = Distance(points[i], points[j]);
            if (d < min_distance) {
                min_distance = d;
            }
        }
    }
}