// 3/16/2023
// John Leeds
// cubetest.cpp
// Test suite for class Cube

#include "cube.h"
#include <iostream>

bool compare(const Cube& c, const std::string& s) {
    for (int i = 0; i < 24; i++) {
        int face = i / 4;
        int piece = i % 4;
        // std::cout << '(' << i << ") Expected: " << s.at(i) << " Actual: " << c.cube[face][piece] << '\n';
        if (c.cube[face][piece] != s.at(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Testing cube:\n";
    {
        Cube c1;
        Cube c2;
        if (c1 != c2) {
            std::cout << "Failed constructor test\n";
        }
    }
    {
        std::string moves[12] = {"R", "R'", "U", "U'", "F", "F'", "L", "L'", "D", "D'", "B", "B'"};
        std::string expected[12] =
        {
            "WGGWGYYGOOOOWBBWRRRRYBBY", // R
            "WBBWGWWGOOOOYBBYRRRRYGGY",
            "WWWWRRGGGGOOOOBBBBRRYYYY", // U
            "WWWWOOGGBBOORRBBGGRRYYYY",
            "WWOOGGGGOYYOBBBBWRRWRRYY", // F
            "WWRRGGGGOWWOBBBBYRRYOOYY",
            "BWWBWGGWOOOOBYYBRRRRGYYG", // L
            "GWWGYGGYOOOOBWWBRRRRBYYB",
            "WWWWGGOOOOBBBBRRRRGGYYYY", // D
            "WWWWGGRROOGGBBOORRBBYYYY",
            "RRWWGGGGWOOWBBBBRYYRYYOO", // B
            "OOWWGGGGYOOYBBBBRWWRYYRR"
        };
        for (int i = 0; i < 12; i++) {
            Cube c;
            c.move(moves[i]);
            if (!compare(c, expected[i])) {
                std::cout << "Failed move test: " << moves[i] << '\n';
            }
        }
    }
    {
        // Scrambled and then solved cube using all 12 possible moves
        Cube c1;
        c1.move("R2 U' F' U' R F2 R F' R U F R' U' F' L D B L' D' B' F U' R U R' U2 L U' L' U2 L U L' U F R U R' U' F' U' R U R' U' R' F R2 U' R' U' R U R' F'");
        Cube c2;
        if (c1 != c2) {
            std::cout << "Failed movement test\n";
        }
    }
    {
        Cube c1;
        c1.move("R");
        Cube c2(c1);
        if (c1 != c2) {
            std::cout << "Failed copy constructor test\n";
        }
    }
    std::cout << "--------\n";
}
