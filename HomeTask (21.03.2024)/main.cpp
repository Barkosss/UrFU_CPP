#include<iostream>
#include<fstream>

#include "fileSystem.h"

int main() {
    
    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    if (!readFile.is_open() || !writeFile.is_open()) {
        std::cout << "Write or Read file isn't found." << std::endl;
        return 404;
    }

    fileSystem(readFile, writeFile);

    return 0;
}