#pragma once

// PipeRoute.h
#ifndef PIPE_ROUTE_H
#define PIPE_ROUTE_H

#include <vector>
#include "../../Lib/CartesianPoint.h"
#include "../../Lib/Vector3D.h"
#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>
#include <math.h>

class PipeRoute {
public:
    void addPoint(const CartesianPoint& point);
    void displayPoints() const;
    void calculateAngles();

private:
    std::vector<CartesianPoint> points;
    std::vector<Vector3D> vectors;

    void calculateVectors();
    double calculateSwivelAngle(const Vector3D& v1, const Vector3D& v2) const;
    double calculateBendAngle(const Vector3D& v1, const Vector3D& v2) const;
};

#endif