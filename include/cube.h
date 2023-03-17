// 3/16/2023
// John Leeds
// cube.h
// Header file for 2x2x2 Rubik's Cube

#ifndef CUBE_HDR
#define CUBE_HDR
#include <string>
#include <vector>

// Converts a color to its index
// WGOBRY -> 012345
int color_index(char color);

// Converts a move to its move index
// Used for getting the correct rotation pattern
// RUFLDB -> 0 2 4 6 8 10 12 (prime moves are odd, so R' -> 1 etc)
int move_index(const std::string& move);


class Cube {
    public:
        // Holds the state of the cube
        // Each array holds 4 characters representing a color (WGOBRY)
        // Note - eventually make this private, overload bracket operator
        char cube[6][4];

        // default constructor - initializes solved Cube
        Cube();

        // constructor - initializes cube to given state
        // Each 4 characters represents the colors of a face in the order
        // U F L B R D
        Cube(const std::string& scramble);

        // copy constructor
        Cube(const Cube& c);

        // constructor - creates a scrambled cube
        Cube(bool scramble);

        // Receives a scramble
        // Applies moves in scramble to cube
        void move(const std::string& scramble);

        // Receives the move (R, U, R', U', etc.)
        // Applies the rotation to the cube.
        void rotate(const std::string& move);

        // Overload ==
        bool operator== (const Cube& other) const;

        // Overload !=
        bool operator!= (const Cube& other) const;

    private:
        bool equals(const Cube& other) const;

        // Receives a scramble and returns a vector of each individual move
        std::vector<std::string> parse_scramble(const std::string& scramble) const;
        
};
#endif
