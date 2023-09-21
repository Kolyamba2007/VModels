#pragma once
#include "Point.h"
#include <list>

namespace VModels
{
	using namespace std;
	class Primitives
	{
	public:
		//Returns points of cube voxels
		static list<Point> Cube(int scale);
		static list<Point> Sphere(int radius);
		static list<Point> Pyramide(int scale);
		static list<Point> Cylinder(int radius);
	};
}