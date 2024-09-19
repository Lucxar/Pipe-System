#include "PipeRoute.h"

void PipeRoute::addPoint(const CartesianPoint& point) {
    points.push_back(point);
}

void PipeRoute::displayPoints() const {
    for (const auto& point : points) {
        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
    }
}

void PipeRoute::calculateVectors() {
    vectors.clear();
    for (size_t i = 1; i < points.size(); ++i) {
        vectors.emplace_back(points[i - 1], points[i]);
    }
}

double PipeRoute::calculateSwivelAngle(const Vector3D& v1, const Vector3D& v2) const {
    double numerator = v1.dotProductXY(v2);
    double denominator = v1.magnitudeXY() * v2.magnitudeXY();

    // Protection against division by zero
    if (denominator == 0) return 0;

    double cosTheta = numerator / denominator;

    // Clamp the value to the range [-1, 1] to avoid numerical errors
    cosTheta = std::max(-1.0, std::min(1.0, cosTheta));

    double angle = std::acos(cosTheta) * (180.0 / M_PI);
    return angle;
}

double PipeRoute::calculateBendAngle(const Vector3D& v1, const Vector3D& v2) const {
    double elevation1 = v1.elevationAngle();
    double elevation2 = v2.elevationAngle();
    double bendAngle = elevation2 - elevation1;
    return bendAngle;
}

void PipeRoute::calculateAngles() {
    if (points.size() < 3) {
        std::cout << "Not enough points to calculate angles. Please enter at least 3 points.\n";
        return;
    }

    calculateVectors();

    for (size_t i = 1; i < vectors.size(); ++i) {
        Vector3D& v1 = vectors[i - 1];
        Vector3D& v2 = vectors[i];

        double swivelAngle = calculateSwivelAngle(v1, v2);
        double bendAngle = calculateBendAngle(v1, v2);

        std::cout << "Between segment " << i << " and " << i + 1 << ":\n";
        std::cout << "  Swivel angle (XY plane): " << swivelAngle << " degrees\n";
        std::cout << "  Bend angle (Z direction): " << bendAngle << " degrees\n";
    }
}
