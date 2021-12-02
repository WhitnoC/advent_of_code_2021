// day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct direction {
public:
    string orientation; //what direction the instruction is
    int amount = 0; //amount to move in
};


int main()
{

    //forward X increases the horizontal position by X units.
    //down X increases the depth by X units.
    //up X decreases the depth by X units.

    int depth = 0;
    int horizontal_position = 0;

    std::vector<direction> directions;

    std::ifstream file;

    std::string line;
    file.open("day2_input.txt");
    if (!file) {
        std::cout << "error reading file" << std::endl;
    };

    while (std::getline(file, line))
    {
        direction new_direction;

        vector<string> instructions;
        string sentence = line;
        istringstream iss(sentence);
        copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            back_inserter(instructions));

        string dir = instructions[0];
        int amt = std::stoi(instructions[1]);

        new_direction.orientation = dir;
        new_direction.amount = amt;

        directions.push_back(new_direction);
    };

    for (int i = 0; i < directions.size(); i++) {
        
            if (directions[i].orientation == "forward") {
                horizontal_position = horizontal_position + directions[i].amount;
            };
            if (directions[i].orientation == "down") {
                depth = (depth + directions[i].amount);
            };
            if (directions[i].orientation == "up") {
                depth = (depth - directions[i].amount);
            };
        };


    int final_amount = horizontal_position * depth;
    cout << "final position is " << final_amount << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
