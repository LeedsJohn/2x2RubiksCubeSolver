// 3/16/2023
// John Leeds
// cube.h
// Header file for 2x2x2 Rubik's Cube

#include <string>

class Cube {
    public:
        // default constructor - initializes solved Cube
        Cube();

        // constructor - initializes cube to given state
        // Each 4 characters represents the colors of a face in the order
        // U F L B R D
        Cube(std::string cube_state);

        // copy constructor
        Cube(const Cube& c);

        // constructor - creates a scrambled cube
        Cube(bool scramble);

        // Receives a scramble
        // Returns a cube that has those moves applied to it
        Cube move(std::string scramble) const;
        
        // move functions - returns a cube after applying that move
        // If clockwise is true, move clockwise. Else counterclockwise.
        Cube right(bool clockwise) const;
        Cube left(bool clockwise) const;
        Cube up(bool clockwise) const;
        Cube down(bool clockwise) const;
        Cube front(bool clockwise) const;
        Cube back(bool clockwise) const;

    private:
        // Holds the state of the cube
        // Each array holds 4 characters representing a color (WGOBRY)
        char cube[6][4];
