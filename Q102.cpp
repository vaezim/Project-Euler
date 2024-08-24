#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


struct Point {
    int x;
    int y;
};
struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};

bool ContainsCentre(const Triangle &t);
Triangle ParseTriangle(const std::string &line);

int main()
{
    // List of all triangles
    std::vector<Triangle> triangles;
    triangles.reserve(30'000);

    // Read triangles
    std::ifstream ifs;
    ifs.open("resources/0102_triangles.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        triangles.emplace_back(ParseTriangle(line));
    }

    // Find # triangles containing (0,0)
    unsigned numTrianglesContainingCentre{ 0 };
    for (const Triangle &t : triangles) {
        numTrianglesContainingCentre += (unsigned)ContainsCentre(t);
    }
    std::cout << "Number of triangles containing centre = "
        << numTrianglesContainingCentre << std::endl;
}

int Sign(int i)
{
    return i >= 0 ? 1 : -1;
}

bool ContainsCentre(const Triangle &t)
{
    const Point &p1 = t.p1;
    const Point &p2 = t.p2;
    const Point &p3 = t.p3;

    int sign1 = ((p1.y - p2.y) * p1.x - (p1.x - p2.x) * p1.y);
    int sign2 = ((p2.y - p3.y) * p2.x - (p2.x - p3.x) * p2.y);
    int sign3 = ((p3.y - p1.y) * p3.x - (p3.x - p1.x) * p3.y);

    return (Sign(sign1) == Sign(sign2)) && (Sign(sign2) == Sign(sign3));
}

Triangle ParseTriangle(const std::string &line)
{
    Triangle triangle;
    std::stringstream ss(line);
    std::string num;
    std::vector<int> nums;
    while (std::getline(ss, num, ',')) {
        nums.push_back(std::stoi(num));
    }
    triangle.p1.x = nums[0];
    triangle.p1.y = nums[1];
    triangle.p2.x = nums[2];
    triangle.p2.y = nums[3];
    triangle.p3.x = nums[4];
    triangle.p3.y = nums[5];
    return triangle;
}