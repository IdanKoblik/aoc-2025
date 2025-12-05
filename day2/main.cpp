#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "../file.h"
#include "../trim.h"

bool isInvalid(const std::string& s);

int main(int argc, char* argv[]) {
    std::ifstream file = getInputFile(argc, argv);
    if (!file) {
        perror("Cannot read input file");
        return -1;
    }

    long long sum1 = 0;
    long long sum2 = 0;

    std::string line;
    while (std::getline(file, line, ',')) {
        trim(&line);
        if (line.empty())
            continue;

        size_t pos = line.find('-');
        if (pos == std::string::npos)
            continue;

        long long x = std::stoll(line.substr(0, pos));
        long long y = std::stoll(line.substr(pos + 1));

        for (long long i = x; i <= y; ++i) {
            std::string s = std::to_string(i);
            if (isInvalid(s)) sum2 += i;
        }

        for (long long i = x; i <= y; ++i) {
            long long digits = std::floor(std::log10(i)) + 1;
            if (digits % 2 == 0) {
                long long half = digits / 2;
                long long pow10 = std::pow(10, half);

                long long left  = i / pow10;
                long long right = i % pow10;

                if (left == right)
                    sum1 += i;
            } 
        }
    }

    std::cout << sum1 << std::endl;
    std::cout << sum2 << std::endl;

    return 0;
}

// part 2
bool isInvalid(const std::string& s) {
    const int n = s.size();

    for (int len = 1; len <= n/2; ++len) {
        if (n % len != 0) continue;

        const std::string base = s.substr(0, len);
        bool ok = true;
        for (int i = len; i < n; i += len) {
            if (s.compare(i, len, base) != 0) {
                ok = false;
                break;
            }
        }

        if (ok)
            return true;
    }

    return false;
}
