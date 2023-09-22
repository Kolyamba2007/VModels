#include "Point.h"
#include <math.h>

namespace VModels
{
	float Point::Distance(Point point1, Point point2)
	{
		return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2) +
			pow(point2.z - point1.z, 2));
	}
}