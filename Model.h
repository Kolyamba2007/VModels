#pragma once
#include "GridPoint.h"
#include <vector>
#include <cmath>
#include "ThirdParty/glm/vec3.hpp"

namespace vmodel {
    class Model {
    protected:
        std::vector<double> FuncResult;
        glm::ivec3 AreaSize;
        void post_construct();
    public:
        std::vector<double>* value() { return &FuncResult; }
        const glm::ivec3& size() const { return AreaSize; }

        Model() = default;
        Model(glm::ivec3 areaSize) : AreaSize(areaSize) {}

        double& operator[](int index) { return FuncResult[index]; }

        void normalize_value();
        std::vector<glm::ivec3> get_points();
		std::vector<std::vector<std::vector<GridPoint>>> get_grid();
    };
}