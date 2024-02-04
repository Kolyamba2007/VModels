#pragma once
#include "GridPoint.h"
#include <vector>

namespace marching
{
	struct MeshData final {
	public:
		std::vector<Point> verts;
		std::vector<Point> normals;
		std::vector<int> indices;

		MeshData(std::vector<Point> verts, std::vector<Point> normals, std::vector<int> indices) : verts(verts), normals(normals), indices(indices) { }

		~MeshData() = default;
	};
}