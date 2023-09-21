#include "VModels.h"

namespace VModels
{
	//Returns points of cube voxels
	list<Point> Primitives::Cube(int scale)
	{
		list<Point> points;
		int step = scale / 2;
		for (int x = 0; x < scale; x++)
		{
			for (int y = 0; y < scale; y++)
			{
				for (int z = 0; z < scale; z++)
				{
					Point point = Point(x - step, y - step, z - step);
					points.push_back(point);
				}
			}
		}
		return points;
	};

	//Returns points of sphere voxels
	list<Point> Primitives::Sphere(int radius)
	{
		list<Point> points;
		for (int x = -radius * 2; x < radius * 2; x++)
		{
			for (int y = -radius * 2; y < radius * 2; y++)
			{
				for (int z = -radius * 2; z < radius * 2; z++)
				{
					Point point = Point(x, y, z);
					if (Point::Distance(point, Point()) < radius)
						points.push_back(point);
				}
			}
		}
		return points;
	};

	//Returns points of pyramide voxels
	list<Point> Primitives::Pyramide(int scale)
	{
		list<Point> points;
		int step = scale / 2;
		for (int y = 0; y < scale / 2 + 1; y++)
		{
			for (int x = y; x < scale - y; x++)
			{
				for (int z = y; z < scale - y; z++)
				{
					Point point = Point(x - step, y - scale / 4, z - step);
					points.push_back(point);
				}
			}
		}
		return points;
	};

	//Returns points of cylinder voxels
	list<Point> Primitives::Cylinder(int radius)
	{
		list<Point> points;
		for (int y = -radius; y < radius; y++)
		{
			Point center = Point(0, y, 0);
			for (int x = -radius; x < radius; x++)
			{
				for (int z = -radius; z < radius; z++)
				{
					Point point = Point(x, y, z);
					if (Point::Distance(point, center) < radius)
						points.push_back(point);
				}
			}
		}
		return points;
	};
}