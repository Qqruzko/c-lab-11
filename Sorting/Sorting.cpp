#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
class Point
{
public:
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	double DistToPoint()
	{
		double d = sqrt((0 - x) * (0 - x) + (0 - y) * (0 - y));
		return d;
	}
	bool operator< (Point);
	friend std::ostream& operator<< (std::ostream& out, const Point& p);
};
bool Point::operator< (Point p1)
{
	if (DistToPoint() < p1.DistToPoint())
		return true;
	else return false;
}
std::ostream& operator<< (std::ostream& out, const Point& p)
{
	out << p.x << " , " << p.y << std::endl;
	return out;
}

int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для // класса Point
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для // класса Point
	return 0;
}