#pragma once
#include "Point.h"

struct GridPoint {
public:
    Point position;
    float value;

    GridPoint(Point pos, float val) : position(pos), value(val) {}
    ~GridPoint() = default;
};