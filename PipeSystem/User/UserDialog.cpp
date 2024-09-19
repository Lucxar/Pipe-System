#include "UserDialog.h"

using namespace std;

void getCoordinate(const string& coordName, double& coord) {
    cout << coordName << ": ";
    while (!(cin >> coord)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}

void UserDialog::inputCoordinates(PipeRoute& route) {
    double x, y, z;
    char more = 'y';

    while (tolower(more) == 'y') {
        cout << "Enter the x, y, z coordinates of the point:\n";
        getCoordinate("x", x);
        getCoordinate("y", y);
        getCoordinate("z", z);

        route.addPoint(CartesianPoint(x, y, z));

        cout << "Do you want to add another point? (y/n): ";
        cin >> more;
        while (tolower(more) != 'y' && tolower(more) != 'n') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> more;
        }
    }
}