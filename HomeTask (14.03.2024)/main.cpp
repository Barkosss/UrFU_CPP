#include<iostream>
#include<fstream>

#include "fileSystem.h"

int main() {
    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    if (!readFile.is_open() || !writeFile.is_open()) {
        std::cout << "Error: File is not open!" << std::endl;
        return 1;
    }

    fileSystem(readFile, writeFile);

    return 0;
}