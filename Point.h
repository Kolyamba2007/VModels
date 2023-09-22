#pragma once
#include "Base.h"

namespace VModels
{
	struct API Point final
	{
	public:
		int x, y, z;

		constexpr Point() noexcept : Point(0, 0, 0) { }
		constexpr Point(int x, int y) noexcept : Point(x, y, 0) { }
		constexpr Point(int x, int y, int z) noexcept
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		constexpr Point(const Point& p) noexcept : Point(p.x, p.y, p.z) { }
		~Point() noexcept = default;

		static float Distance(Point point1, Point point2);
	};
}