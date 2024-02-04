#include "Model.h"

namespace vmodel
{
    void Model::post_construct() {
        normalize_value();
    }

    void Model::normalize_value() {
        double maxValue = std::numeric_limits<double>::min();

        int it = 0;
        for (int z = 0; z < AreaSize.z; z++)
            for (int y = 0; y < AreaSize.y; y++)
                for (int x = 0; x < AreaSize.x; x++)
                {
                    if (std::abs(FuncResult[it]) > maxValue)
                        maxValue = FuncResult[it];

                    it++;
                }

        for (int i = 0; i < FuncResult.size(); i++)
            FuncResult[i] /= maxValue;
    }

    std::vector<glm::ivec3> Model::get_points()
    {
        std::vector<glm::ivec3> p;

        int it = 0;
        for (int x = 0; x < AreaSize.x; x++)
            for (int y = 0; y < AreaSize.y; y++)
                for (int z = 0; z < AreaSize.z; z++) {
                    if (FuncResult[it] <= 0)
                        p.push_back(glm::ivec3(x, y, z));
                    it++;
                }

        return p;
    }

    std::vector<std::vector<std::vector<GridPoint>>> Model::get_grid()
    {
        auto p = std::vector<std::vector<std::vector<GridPoint>>>();
        p.resize(AreaSize.x);
        for (int i = 0; i < AreaSize.x; i++)
        {
            p[i].resize(AreaSize.y);
            for (int j = 0; j < AreaSize.y; j++)
                p[i][j].resize(AreaSize.z);
        }

        int it = 0;
        for (int z = 0; z < AreaSize.z; z++)
            for (int y = 0; y < AreaSize.y; y++)
                for (int x = 0; x < AreaSize.x; x++) {
                    p[x][y][z] = GridPoint(
                        glm::ivec3(x, y, z),
                        -(float)FuncResult[it]
                    );
                    it++;
                }

        return p;
    }
}