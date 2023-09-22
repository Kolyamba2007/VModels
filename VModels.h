#pragma once
#include "Point.h"

namespace VModels
{
	using Points = std::vector<Point>;

	class API Primitives
	{
	public:
		//Returns points of cube voxels
		static Points Cube(int scale);
		static Points Sphere(int radius);
		static Points Pyramide(int scale);
		static Points Cylinder(int radius);
	};
}