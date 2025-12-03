#include <iostream>
#include <fstream>
#include <string>
#include <deque>

#include "../file.h"

std::string largestNumber(const std::string &line, int k);

int main(int argc, char* argv[]) {
    std::ifstream file = getInputFile(argc, argv);
    if (!file) {
        perror("Cannot read input file");
        return -1;
    }

    std::string line;
    long long sumPart1 = 0;
    long long sumPart2 = 0;

    while (std::getline(file, line)) {
        int max = 0;
        int maxDigit = line[0] - '0';
        for (int i = 1; i < line.length(); i++) {
            int num = maxDigit * 10 + (line[i] - '0');
            if (num > max)
                max = num;

            if ((line[i] - '0') > maxDigit)
                maxDigit = (line[i] - '0');
        }
        sumPart1 += max;

        int k = 12;
        std::string largest12 = largestNumber(line, k);
        sumPart2 += std::stoll(largest12);
    }

    std::cout << "[PART1] " << sumPart1 << std::endl;
    std::cout << "[PART2] " << sumPart2 << std::endl;
    return 0;
}

std::string largestNumber(const std::string &line, int k) {
    std::deque<char> stack;
    int n = line.size();

    for (int i = 0; i < n; i++) {
        char c = line[i];
        while (!stack.empty() && stack.back() < c && (stack.size() - 1 + (n - i)) >= k)
            stack.pop_back();

        if (stack.size() < k)
            stack.push_back(c);
    }

    std::string result;
    for (char c : stack)
        result += c;

    return result;
}

