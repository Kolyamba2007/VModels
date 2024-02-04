#include "Model.h"

namespace vmodel
{
    class Ellipsoid : public Model
    {
    public:
        Ellipsoid() : Ellipsoid(1, 2, 3, { 0, 0, 0 }, { 128, 128, 128 }) { }
        Ellipsoid(double a, double b, double c, glm::ivec3 center, glm::ivec3 areaSize)
        {
            AreaSize = areaSize;

            for (int x = 0; x < AreaSize.x; x++)
                for (int y = 0; y < AreaSize.y; y++)
                    for (int z = 0; z < AreaSize.z; z++)
                        FuncResult.push_back(ellipsoid_func(a, b, c, center.x, center.y, center.z, x, y, z));
        
            post_construct();
        }

        double ellipsoid_func(double a, double b, double c, double X1, double Y1, double Z1, double x, double y, double z)
        {
            return pow(x - X1, 2) / (a * a) + pow(y - Y1, 2) / (b * b) + pow(z - Z1, 2) / (c * c) - 1;
        }
    };
}