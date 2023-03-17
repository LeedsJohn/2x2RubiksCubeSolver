// 3/16/2023
// John Leeds
// cube.h
// Header file for 2x2x2 Rubik's Cube

#ifndef CUBE_HDR
#define CUBE_HDR
#include <string>

// Converts a color to its index
// WGOBRY -> 012345
int color_index(char color);

// Converts a move to its move index
// Used for getting the correct rotation pattern
// RUFLDB -> 0 2 4 6 8 10 12 (prime moves are odd, so R' -> 1 etc)
int move_index(const std::string& move);

char COLORS[6] = {'W', 'G', 'O', 'B', 'R', 'Y'};

char MOVES[6] = {"R", "U", "F", "L", "D", "B"};

int MOVE_PATTERNS[12][8] =
{
    {0, 3, 5, 1, 1, 3, 1, 1, 2, 0, 2, 2, 4}, // R
    {0, 1, 5, 3, 1, 1, 1, 3, 2, 2, 2, 0, 4}, // R'
    {1, 2, 3, 4, 0, 0, 0, 0, 1, 1, 1, 1, 0}, // U
    {1, 4, 3, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0}, // U'
    {0, 4, 5, 2, 2, 4, 0, 1, 3, 0, 1, 2, 1}, // F
    {0, 2, 5, 4, 2, 1, 0, 4, 3, 2, 1, 0, 1}, // F'
    {0, 1, 5, 3, 0, 0, 0, 2, 3, 3, 3, 1, 2}, // L
    {0, 3, 5, 1, 0, 2, 0, 0, 3, 1, 3, 3, 2}, // L'
    {1, 4, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5}, // D
    {1, 2, 3, 4, 2, 2, 2, 2, 3, 3, 3, 3, 5}, // D'
    {0, 2, 5, 4, 0, 3, 2, 1, 1, 0, 3, 2, 3}, // B
    {0, 4, 5, 2, 0, 1, 2, 3, 1, 2, 3, 0, 3} // B'
}

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
        // Returns a cube that has those moves applied to it
        Cube move(std::string scramble) const;
        
        // move functions - returns a cube after applying that move
        // If clockwise is true, move clockwise. Else counterclockwise.
        void right(bool clockwise);
        void left(bool clockwise);
        void up(bool clockwise);
        void down(bool clockwise);
        void front(bool clockwise);
        void back(bool clockwise);

        // Overload ==
        bool operator== (const Cube& other) const;

        // Overload !=
        bool operator!= (const Cube& other) const;

    private:
        bool equals(const Cube& other) const;
        
        // Receives the index of the move
        // Applies the rotation to the cube.
        void rotate(int rotate_index);

};
#endif
