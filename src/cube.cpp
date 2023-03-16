// 3/16/2023
// John Leeds
// cube.cpp
// Implementation file for 2x2x2 Rubik's Cube

#include <include/cube.h>

// default constructor - initializes solved Cube
Cube::Cube() {
    return;
}

// constructor - initializes cube to given state
// Each 4 characters represents the colors of a face in the order
// U F L B R D
Cube::Cube(std::string cube_state) {
    return;
}

// copy constructor
Cube::Cube(const Cube& c) {
    return;
}

// constructor - creates a scrambled cube
Cube::Cube(bool scramble) {
    return;
}

// Receives a scramble
// Returns a cube that has those moves applied to it
Cube::Cube move(std::string scramble) const {
    return;
}

// move functions - returns a cube after applying that move
// If clockwise is true, move clockwise. Else counterclockwise.
Cube::Cube right(bool clockwise) const {
    return;
}

Cube::Cube left(bool clockwise) const {
    return;
}
Cube::Cube up(bool clockwise) const {
    return;
}
Cube::Cube down(bool clockwise) const {
    return;
}
Cube::Cube front(bool clockwise) const {
    return;
}
Cube::Cube back(bool clockwise) const {
    return;
}
