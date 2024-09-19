# PipeSystem

The `PipeSystem` project is designed to manage and calculate complex routes for pipe-like structures in a 3D space. This system provides functionality for working with points in a Cartesian coordinate system, vectors, and routes that define the paths of pipes. It is especially suited for applications in simulations, games, and engineering tools that require precise control over 3D pathfinding and pipe geometry.

## Key Features

- **CartesianPoint**: Represents a point in 3D space using Cartesian coordinates (X, Y, Z).
- **Vector3D**: A class for handling vector mathematics in 3D space, allowing operations such as addition, subtraction, and scaling.
- **PipeRoute**: Defines a route for a pipe, including the ability to calculate paths, lengths, and other properties related to the geometry of the pipe.

## Classes Overview

### CartesianPoint

The `CartesianPoint` class encapsulates a point in a 3D Cartesian coordinate system with the following properties:

- `X`: The X-coordinate of the point.
- `Y`: The Y-coordinate of the point.
- `Z`: The Z-coordinate of the point.

#### Key Methods:
- **DistanceTo**: Calculates the distance between two `CartesianPoint` objects.
- **Move**: Translates the point by a given `Vector3D`.

### Vector3D

The `Vector3D` class represents a vector in 3D space and provides various vector operations that are essential for manipulating points and defining pipe directions.

#### Key Methods:
- **Add**: Adds two vectors together.
- **Subtract**: Subtracts one vector from another.
- **Normalize**: Returns the unit vector in the same direction.
- **DotProduct**: Computes the dot product between two vectors.
- **CrossProduct**: Computes the cross product of two vectors.

### PipeRoute

The `PipeRoute` class manages the path of a pipe, which is defined by a series of `CartesianPoint` objects. It calculates the total length of the pipe and provides various tools for determining the layout and geometry.

#### Key Methods:
- **AddPoint**: Adds a new point to the pipe route.
- **CalculateLength**: Calculates the total length of the pipe route by summing the distances between consecutive points.
- **FindClosestPoint**: Finds the closest point on the pipe route to a given location.

## Getting Started

### Prerequisites

- This project is developed using **Rider IDE**, and you will need it or another compatible IDE to compile and run the code.
- Basic understanding of 3D vector mathematics and geometry is recommended.

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/maystudios/PipeSystem.git
    ```

2. Open the project in **Rider IDE** or your preferred IDE.

3. Build and run the project to explore the functionality provided by the `PipeSystem`.

## Usage

To start using the `PipeSystem`, you can instantiate a `PipeRoute` and add `CartesianPoint` objects to it, like this:

```csharp
// Create a new pipe route
PipeRoute pipeRoute = new PipeRoute();

// Add points to the route
pipeRoute.AddPoint(new CartesianPoint(0, 0, 0));
pipeRoute.AddPoint(new CartesianPoint(1, 1, 0));

// Calculate the total length of the pipe route
double length = pipeRoute.CalculateLength();
Console.WriteLine($"Total pipe length: {length}");
