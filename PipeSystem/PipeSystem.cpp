// #include <iostream>
// #include <vector>
// #include <cmath>

#include <iostream>

#include "User/Router/PipeRoute.h"
#include "Lib/CartesianPoint.h"
#include "User/UserDialog.h"

using namespace std;

void autonomousPointsFillOut(PipeRoute& route);

int main() {
    
    PipeRoute route;

    UserDialog::inputCoordinates(route);

    route.displayPoints();
    route.calculateAngles();

    system("pause"); 
    cout << "Done"; 
}

void autonomousPointsFillOut(PipeRoute& route) {
    
    route.addPoint(CartesianPoint(0, 0, 0));
    route.addPoint(CartesianPoint(1, 0, 1));
    route.addPoint(CartesianPoint(2, 0, 1));
    route.addPoint(CartesianPoint(3, 1, 2));
}