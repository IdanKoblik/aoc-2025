#include "file.h"

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

std::ifstream getInputFile(int argc, char* argv[]) {
    std::string filename;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.rfind("--file=", 0) == 0) {
            filename = arg.substr(7);
        } else if (arg == "-f" && i + 1 < argc) {
            filename = argv[++i];
        }
    }

    if (filename.empty()) {
        perror("No file provided. Use --file=<name>.txt or -f <name>.txt");
        return {};
    }

    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt") {
        perror("Only .txt files are supported.");
        return {};
    }

    std::filesystem::path path = std::filesystem::current_path() / filename;

    if (!std::filesystem::exists(path)) {
        perror("File does not exist in the program folder.");
        return {};
    }

    std::ifstream file(path);
    if (!file.is_open()) {
        perror("Failed to open file!");
        return {};
    }

    return file;
}