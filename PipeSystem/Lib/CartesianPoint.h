#pragma once

#ifndef CARTESIAN_POINT_H
#define CARTESIAN_POINT_H

#include <iostream>

class CartesianPoint {
public:
    double x, y, z;

    CartesianPoint(double x, double y, double z);
    void print() const;
};

#endif