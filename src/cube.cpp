// 3/16/2023
// John Leeds
// cube.cpp
// Implementation file for 2x2x2 Rubik's Cube

#include "cube.h"
#include <iostream> // REMOVE THIS

char COLORS[6] = {'W', 'G', 'O', 'B', 'R', 'Y'};

char MOVES[6] = {'R', 'U', 'F', 'L', 'D', 'B'};

int MOVE_PATTERNS[12][13] =
{
    {0, 3, 5, 1, 1, 3, 1, 1, 2, 0, 2, 2, 4}, // R
    {0, 1, 5, 3, 1, 1, 1, 3, 2, 2, 2, 0, 4}, // R'
    {1, 2, 3, 4, 0, 0, 0, 0, 1, 1, 1, 1, 0}, // U
    {1, 4, 3, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0}, // U'
    {0, 4, 5, 2, 2, 3, 0, 1, 3, 0, 1, 2, 1}, // F
    {0, 2, 5, 4, 2, 1, 0, 3, 3, 2, 1, 0, 1}, // F'
    {0, 1, 5, 3, 0, 0, 0, 2, 3, 3, 3, 1, 2}, // L
    {0, 3, 5, 1, 0, 2, 0, 0, 3, 1, 3, 3, 2}, // L'
    {1, 4, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5}, // D
    {1, 2, 3, 4, 2, 2, 2, 2, 3, 3, 3, 3, 5}, // D'
    {0, 2, 5, 4, 0, 3, 2, 1, 1, 0, 3, 2, 3}, // B
    {0, 4, 5, 2, 0, 1, 2, 3, 1, 2, 3, 0, 3} // B'
};

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
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cube[i][j] = COLORS[i];
        }
    }
}

// constructor - initializes cube and applies a given scramble
Cube::Cube(std::string scramble) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cube[i][j] = COLORS[i];
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
void Cube::move(const std::string& scramble) {
    std::vector<std::string> moves = parse_scramble(scramble);
    for (std::string m : moves) {
        rotate(m);
    }
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

// Receives a scramble and returns a vector of each individual move
std::vector<std::string> Cube::parse_scramble(const std::string& scramble) const {
    size_t n = scramble.length();
    std::string valid_moves = "RUFLDB";
    std::vector<std::string> res;
    for (size_t i = 0; i < n; i++) {
        char cur = scramble.at(i);
        if (valid_moves.find(cur) == std::string::npos) {
            continue; // ignore all characters that aren't RUFLDB
        }
        std::string cur_move(1, cur);
        if (i + 1 == n) {
            res.push_back(cur_move);
        } else if (scramble.at(i + 1) == '\'') {
            cur_move.append("'");
            res.push_back(cur_move);
        } else {
            res.push_back(cur_move);
            if (scramble.at(i + 1) == '2') {
                res.push_back(cur_move);
            }
        }
    }
    return res;
}

// Receives the move (R, U, R', U', etc.)
// Applies the rotation to the cube.
void Cube::rotate(const std::string& move) {
    int rotate_index = move_index(move);
    int* pattern = MOVE_PATTERNS[rotate_index];
    char temp = cube[pattern[3]][pattern[7]];
    for (int i = 3; i > 0; i--) {
        cube[pattern[i]][pattern[4 + i]] = cube[pattern[i - 1]][pattern[3 + i]];
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
