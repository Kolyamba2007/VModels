#pragma once
#include "Point.h"
#include <vector>
#include <cmath>

namespace VModel {
    class Model {
    protected:
        std::vector<double> FuncResult;
        Point AreaSize;

    public:
        std::vector<double> Value() { return FuncResult; }
        Point Size() { return AreaSize; }

        Model(Point areaSize) : AreaSize(areaSize) {}

		std::vector<Point> GetPoints();
    };
}