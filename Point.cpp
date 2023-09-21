#include "Point.h"

class Point
{
public:
	int x, y, z;

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	};

	static float Distance(Point point1, Point point2)
	{
		return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2) +
			pow(point2.z - point1.z, 2));
	}
};