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

    std::vector<std::vector<std::vector<GridPoint>>> Model::get_points()
	{
        std::vector<std::vector<std::vector<GridPoint>>> result;

        int it = 0;
        for (int x = 0; x < AreaSize.x; x++)
            for (int y = 0; y < AreaSize.y; y++)
                for (int z = 0; z < AreaSize.z; z++) {
                    if (FuncResult[it] <= 0)
                        result[x][y][z] = GridPoint(
                            Point(x, y, z),
                            -(float) FuncResult[it]
                        );
                    it++;
                }

        return result;
	}
}