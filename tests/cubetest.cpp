// 3/16/2023
// John Leeds
// cubetest.cpp
// Test suite for class Cube

#include "cube.h"
#include <iostream>

int main() {
    std::cout << "Testing cube:\n"
    {
        Cube c1;
        Cube c2;
        if (c1 != c2) {
            std::cout << "Failed constructor test\n";
        }
    }
    {
        // Scrambled and then solved cube using all 12 possible moves
        Cube c1("R2 U' F' U' R F2 R F' R U F R' U' F' L D B L' D' B' F U' R U R' U2 L U' L' U2 L U L' U F R U R' U' F' U' R U R' U' R' F R2 U' R' U' R U R' F'");
        Cube c2();
        if (c1 != c2) {
            std::cout << "Failed movement test\n";
        }
    }
    {
        Cube c1("R");
        Cube c2(c1);
        if (c1 != c2) {
            std::cout << "Failed copy constructor test\n";
        }
    }
    std::cout << "--------\n";
}
