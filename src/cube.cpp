// 3/16/2023
// John Leeds
// cube.cpp
// Implementation file for 2x2x2 Rubik's Cube

#include "cube.h"

// default constructor - initializes solved Cube
Cube::Cube() {
    char colors[6] = {'W', 'G', 'O', 'B', 'R', 'Y'};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cube[i][j] = colors[i];
        }
    }
}

// constructor - initializes cube and applies a given scramble
Cube::Cube(const std::string& scramble) {
    char colors[6] = {'W', 'G', 'O', 'B', 'R', 'Y'};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cube[i][j] = colors[i];
        }
    }
    move(scramble);
}

// copy constructor
Cube::Cube(const Cube& c) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cube[i][j] = c.cube[i][j];
        }
    }
}

// constructor - creates a scrambled cube
// UNIMPLEMENTED
Cube::Cube(bool scramble) {
    return;
}

// Receives a scramble
// Applies moves in scramble to cube
void Cube::move(std::string scramble) {
    
    return;
}

// move functions -  applies specified move
// If clockwise is true, move clockwise. Else counterclockwise.
void Cube::right(bool clockwise) {
    return;
}

void Cube::left(bool clockwise) {
    return;
}

void Cube::up(bool clockwise) {
    return;
}

void Cube::down(bool clockwise) {
    return;
}

void Cube::front(bool clockwise) {
    return;
}

void Cube::back(bool clockwise) {
    return;
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
