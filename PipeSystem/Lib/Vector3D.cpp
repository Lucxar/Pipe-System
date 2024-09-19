#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D::Vector3D(const CartesianPoint& start, const CartesianPoint& end) {
    x = end.x - start.x;
    y = end.y - start.y;
    z = end.z - start.z;
}

double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3D::magnitudeXY() const {
    return std::sqrt(x * x + y * y);
}

double Vector3D::horizontalMagnitude() const {
    return magnitudeXY();
}

double Vector3D::dotProductXY(const Vector3D& other) const {
    return x * other.x + y * other.y;
}

double Vector3D::elevationAngle() const {
    return std::atan2(z, horizontalMagnitude()) * (180.0 / M_PI);
}