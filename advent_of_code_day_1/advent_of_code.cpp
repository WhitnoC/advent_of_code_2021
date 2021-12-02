// advent_of_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <fstream>


using namespace std;

int main()
{

    //load the depth measurements:
    std::ifstream file;
    file.open("day1_input.txt");
    if (!file) {
        std::cout << "error reading file" << std::endl;
    };

    //read depth measurements and append to list
    std::vector<int> depth_measurements;
    std::string line;
    while (std::getline(file, line))
    {
        int current_num = std::stoi(line);
        depth_measurements.push_back(current_num);
    };


    int times_increased = 0; //to measure times increased
    for (unsigned int i = 0; i < depth_measurements.size(); i++)
    {
        int current_measurement = depth_measurements[i];
        if (i >= 1) {
            int previous_measurement = depth_measurements[i - 1];
            if (current_measurement > previous_measurement) {
                times_increased = times_increased + 1;
            };
        };
    };

    std::cout << "Number of times depth measurement increased was: " << times_increased << std::endl;

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
