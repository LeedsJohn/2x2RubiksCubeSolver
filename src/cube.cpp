// 3/16/2023
// John Leeds
// cube.cpp
// Implementation file for 2x2x2 Rubik's Cube

#include "cube.h"

// Converts a color to its index
// WGOBRY -> 012345
int color_index(char color) {
    for (int i = 0; i < 6; i++) {
        if (COLORS[i] == color) {
            return i;
        }
    }
    return -1;
}

// Converts a move to its move index
// Used for getting the correct rotation pattern
// RUFLDB -> 0 2 4 6 8 10 12 (prime moves are odd, so R' -> 1 etc)
int move_index(const std::string& move) {
    char first = move.at(0);
    int add = 0;
    if (move.length() > 1 && move.at(1) == '\'') {
        add++;
    }
    for (int i = 0; i < 6; i++) {
        if (MOVES[i] == first) {
            return i * 2 + add;
        }
    }
    return -1;
}

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

// Receives the move (R, U, R', U', etc.)
// Applies the rotation to the cube.
void Cube::rotate(const std::string& move) {
    int rotate_index = move_index(move);
    int* pattern = MOVE_PATTERNS[rotate_index];
    char temp = cube[pattern[3]][pattern[7]];
    for (int i = 3; i > 0; i--) {
        cube[pattern[i]][pattern[4 + i]] = cube[pattern[i - 1]][pattern[4 + i]];
    }
    cube[pattern[0]][pattern[4]] = temp;

    temp = cube[pattern[3]][pattern[11]];
    for (int i = 3; i > 0; i--) {
        cube[pattern[i]][pattern[8 + i]] = cube[pattern[i - 1]][pattern[7 + i]];
    }
    cube[pattern[0]][pattern[8]] = temp;
    
    int rotate_face = pattern[12];
    temp = cube[rotate_face][3];
    for (int i = 3; i > 0; i--) {
        cube[rotate_face][i] = cube[rotate_face][i - 1];
    }
    cube[rotate_face][0] = temp;
}
