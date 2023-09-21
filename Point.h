#pragma once

class Point
{
public:
	int x, y, z;
	Point() {};
	Point(int x, int y, int z);
	static float Distance(Point point1, Point point2);
};