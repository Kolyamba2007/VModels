#pragma once
#include "GridPoint.h"
#include <vector>
#include <cmath>

namespace vmodel {
    class Model {
    protected:
        std::vector<double> FuncResult;
        Point AreaSize;
        void post_construct();
    public:
        std::vector<double>* value() { return &FuncResult; }
        const Point& size() const { return AreaSize; }

        Model() = default;
        Model(Point areaSize) : AreaSize(areaSize) {}

        double& operator[](int index) { return FuncResult[index]; }

        void normalize_value();
		std::vector<std::vector<std::vector<GridPoint>>> get_points();
    };
}