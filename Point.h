#pragma once
#include <cmath>

struct Point final {
public:
    int x, y, z;

    constexpr Point() noexcept : Point(0, 0, 0) { }
    constexpr Point(int x, int y) noexcept : Point(x, y, 0) { }
    constexpr Point(int x, int y, int z) noexcept : x(x), y(y), z(z) { }
    constexpr Point(const Point& p) noexcept : Point(p.x, p.y, p.z) { }

    ~Point() noexcept = default;

    Point normalize() {
        float length = std::sqrt(x * x + y * y + z * z);
        return Point(x / length, y / length, z / length);
    }

    const Point operator-() {
        return Point(-x, -y, -z);
    }
};

static const bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

static const bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}