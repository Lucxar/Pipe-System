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

## Mathematical Explanation

### Swivel Angle (XY-Plane)
The **swivel angle** is the angle between two vectors in the XY-plane, which represents how much a pipe bends horizontally. To calculate the swivel angle between two consecutive pipes (represented as vectors `v1` and `v2`), we use the dot product formula:

```tex
$\[\theta = \arccos\left(\frac{v1_x \cdot v2_x + v1_y \cdot v2_y}{|v1| \cdot |v2|}\right)\]$
```

Where:
- \( v1_x \) and \( v1_y \) are the X and Y components of the first vector.
- \( v2_x \) and \( v2_y \) are the X and Y components of the second vector.
- \( |v1| \) and \( |v2| \) are the magnitudes of the vectors.

This formula gives the angle in radians, which is then converted to degrees.

### Bend Angle (Z-Axis)
The **bend angle** represents the vertical angle between two pipes. To compute the bend angle, we calculate the elevation angle (the angle between the vector and the XY-plane) for each vector and then determine the difference:

1. **Elevation Angle of a Vector**:
```tex
   \[
   \phi = \arctan\left(\frac{z}{\sqrt{x^2 + y^2}}\right)
   \]
```
   Where:
   - \( z \) is the Z-component of the vector.
   - \( x \) and \( y \) are the X and Y components of the vector, respectively.
   
2. **Bend Angle**:
   The bend angle between two consecutive pipes is simply the difference between their elevation angles:
```tex
   \[
   \Delta \phi = \phi_2 - \phi_1
   \]
```

These calculations are used to determine how much a pipe system bends horizontally and vertically between consecutive segments, providing both a swivel angle (in the XY-plane) and a bend angle (in the Z-axis).

## Example

Input:
```bash
Enter the x, y, z coordinates of the point:
x: 4
y: 4
z: 4
Do you want to add another point? (y/n): z
Invalid input. Please enter 'y' or 'n': y
Enter the x, y, z coordinates of the point:
x: 7
y: 4
z: 4
Do you want to add another point? (y/n): y
Enter the x, y, z coordinates of the point:
x: 7
y: 7
z: 4
Do you want to add another point? (y/n): y
Enter the x, y, z coordinates of the point:
x: 10
y: 7
z: 4
```

Output:
```bash
Point: (4, 4, 4)
Point: (7, 4, 4)
Point: (7, 7, 4)
Point: (10, 7, 4)
Between segment 1 and 2:
  Swivel angle (XY plane): 90 degrees
  Bend angle (Z direction): 0 degrees
Between segment 2 and 3:
  Swivel angle (XY plane): -90 degrees
  Bend angle (Z direction): 0 degrees
Press any button . . .
```

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
