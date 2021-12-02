
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

    cout << "files collected. There are " << depth_measurements.size() << " entries." << std::endl;

    int times_increased = 0; //to measure times increased
    std::vector<int> measurement_sums;
    for (unsigned int i = 0; i < depth_measurements.size(); i++)
    {
        int current_measurement = depth_measurements[i];
        if (i >= 2) {
            int measurement_1_behind = depth_measurements[i - 1];
            int measurement_2_behind = depth_measurements[i - 2];

            int sum = current_measurement + measurement_1_behind + measurement_2_behind;
            measurement_sums.push_back(sum);
        }
        else {
            cout << "skipped" << endl;
        }

    };

    for (unsigned int i = 0; i < measurement_sums.size(); i++) {
        int current_measurement = measurement_sums[i];
        if (i >= 1) {
            int previous_measurement = measurement_sums[i - 1];
            if (current_measurement > previous_measurement) {
                times_increased = times_increased + 1;
            };
        };
    }

    std::cout << "Number of times depth measurement increased was: " << times_increased << std::endl;

}

