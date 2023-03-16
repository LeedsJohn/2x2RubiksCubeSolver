// 3/16/2023
// John Leeds
// cube.cpp
// Implementation file for 2x2x2 Rubik's Cube

#include <cube.h>

// default constructor - initializes solved Cube
Cube::Cube() {
    char colors[6] = {'W', 'G', 'O', 'B', 'R', 'Y'};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cube[i][j] = colors[i];
        }
    }
}

// constructor - initializes cube to given state
// Each 4 characters represents the colors of a face in the order
// U F L B R D
Cube::Cube(const std::string& cube_state) {
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
Cube Cube::move(std::string scramble) const {
    Cube temp();
    return temp;
}

// move functions - returns a cube after applying that move
// If clockwise is true, move clockwise. Else counterclockwise.
Cube Cube::right(bool clockwise) const {
    Cube temp();
    return temp;
}

Cube Cube::left(bool clockwise) const {
    Cube temp();
    return temp;
}

Cube Cube::up(bool clockwise) const {
    Cube temp();
    return temp;
}

Cube Cube::down(bool clockwise) const {
    Cube temp();
    return temp;
}

Cube Cube::front(bool clockwise) const {
    Cube temp();
    return temp;
}

Cube Cube::back(bool clockwise) const {
    Cube temp();
    return temp;
}
// Overload ==
bool Cube::operator== (const Cube& other) const {
    return equals(other);
}

bool Cube::operator!= (const Cube& other) const {
    return !(equals(other));
}

bool Cube::equals(const Cube& other) const {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (cube[i][j] != other.cube[i][j]) {
                return false;
            }
        }
    }
    return true;
}
