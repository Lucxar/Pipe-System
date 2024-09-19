#pragma once

#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "CartesianPoint.h"
#include <cmath>
#include <cmath>
#include <math.h>

#include <corecrt_math_defines.h>
#define _USE_MATH_DEFINES

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x = 0, double y = 0, double z = 0);
    Vector3D(const CartesianPoint& start, const CartesianPoint& end);

    double magnitude() const;
    double magnitudeXY() const;
    double horizontalMagnitude() const;
    double dotProductXY(const Vector3D& other) const;
    double elevationAngle() const;
};

#endif

