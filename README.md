# Pipe System

Pipe System is a C++ application that allows users to input and manage points in a 3D space, calculate the angles between consecutive pipes, and display the information in a user-friendly manner. The system is designed to help with visualization and computation of angles in a pipe routing system.

## Features

- **User Input**: Easily input points in a 3D space using the `UserDialog` class.
- **Point Management**: Store and display points using the `PipeRoute` class.
- **Angle Calculation**: Calculate both swivel (XY-plane) and bend (Z-axis) angles between consecutive pipes.
- **Vector Operations**: Perform vector calculations such as magnitudes, dot products, and elevation angles using the `Vector3D` class.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/Pipe-System.git
    cd Pipe-System
    ```

2. Build the project using your preferred C++ compiler.

## Usage

1. Run the compiled application.
2. You will be prompted to input the x, y, and z coordinates of each point.
3. Once you have inputted all points, the system will display the following:
    - The coordinates of the points you entered.
    - The calculated swivel angles (XY-plane) and bend angles (Z-axis) between each consecutive point.

## Code Overview

### Main Functions

- `main()`: The entry point of the program that initiates the `PipeRoute` and collects user input using the `UserDialog` class. It also triggers the display of points and the calculation of angles.
- `autonomousPointsFillOut(PipeRoute& route)`: A helper function that pre-fills the `PipeRoute` with predefined points for testing.

### Classes and Methods

#### CartesianPoint

Represents a point in 3D space.

- `CartesianPoint(double x, double y, double z)`: Constructor to initialize a point.
- `void print() const`: Prints the point’s coordinates.

#### Vector3D

Represents a 3D vector for performing calculations between points.

- `Vector3D(double x, double y, double z)`: Constructor to initialize a vector.
- `Vector3D(const CartesianPoint& start, const CartesianPoint& end)`: Constructs a vector between two points.
- `double magnitude() const`: Calculates the vector's magnitude.
- `double magnitudeXY() const`: Calculates the vector's magnitude in the XY plane.
- `double horizontalMagnitude() const`: Alias for `magnitudeXY()`.
- `double dotProductXY(const Vector3D& other) const`: Calculates the dot product in the XY-plane.
- `double elevationAngle() const`: Calculates the elevation angle (Z-axis) of the vector.

#### PipeRoute

Stores the route made of `CartesianPoint` objects and performs vector calculations between points.

- `void addPoint(const CartesianPoint& point)`: Adds a new point to the route.
- `void displayPoints() const`: Displays all points in the route.
- `void calculateAngles()`: Calculates both swivel and bend angles between consecutive points.
- `void calculateVectors()`: Helper function that generates vectors between each point.
- `double calculateSwivelAngle(const Vector3D& v1, const Vector3D& v2) const`: Calculates the angle between two vectors in the XY plane.
- `double calculateBendAngle(const Vector3D& v1, const Vector3D& v2) const`: Calculates the bend angle between two vectors in the Z axis.

#### UserDialog

Handles the user interface for inputting coordinates.

- `static void inputCoordinates(PipeRoute& route)`: Gathers user input to populate the `PipeRoute` with points.

## Example

```bash
Enter the x, y, z coordinates of the point:
x: 1
y: 2
z: 3
Do you want to add another point? (y/n): y

Enter the x, y, z coordinates of the point:
x: 4
y: 5
z: 6
Do you want to add another point? (y/n): n
```

```bash
Output:

java

Points entered:
(1, 2, 3)
(4, 5, 6)

Swivel angle (XY direction): 45 degrees
Bend angle (Z direction): 30 degrees
```

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
