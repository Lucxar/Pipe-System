#pragma once

#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include "Router/PipeRoute.h"
#include "../Lib/CartesianPoint.h"
#include <iostream>

using namespace std;

class UserDialog {
public:
    static void inputCoordinates(PipeRoute& route);
};

#endif