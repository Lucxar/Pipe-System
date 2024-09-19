#include "CartesianPoint.h"

CartesianPoint::CartesianPoint(double x, double y, double z) : x(x), y(y), z(z) {}

void CartesianPoint::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}