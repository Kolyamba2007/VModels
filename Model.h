#pragma once
#include "GridPoint.h"
#include "Direction.h"
#include <vector>
#include <cmath>
#include "ThirdParty/glm/vec3.hpp"

namespace vmodel {
    class Model {
    protected:
        std::vector<double> func_result;
        glm::ivec3 area_size{};
        void post_construct();
    public:
        std::vector<double>* value() { return &func_result; }
        const glm::ivec3& size() const { return area_size; }

        Model() = default;
        Model(glm::ivec3 area_size) : area_size(area_size) {}

        double& operator[](int index) { return func_result[index]; }

        void normalize_value();
        std::vector<glm::ivec3> get_points();
		std::vector<std::vector<std::vector<GridPoint>>> get_grid();
    };
}