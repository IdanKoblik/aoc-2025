#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "../file.h"

int main(int argc, char* argv[]) {
    std::ifstream file = getInputFile(argc, argv);
    if (!file) {
        perror("Cannot read input file");
        return -1;
    }

    int dial = 50;
    int part1 = 0;
    int part2 = 0;

    std::string line;
    while (std::getline(file, line)) {
        char direction = line[0];
        int value = std::stoi(line.substr(1));

        for (int i = 0; i < value; ++i) {
            dial = direction == 'L' ? (dial - 1 + 100) % 100 : (dial + 1) % 100;
            if (dial == 0)
                part2++;
        }

        if (dial == 0)
            part1++;
    }

    std::cout << part1 << std::endl;
    std::cout << part2 << std::endl;

    return 0;
}
