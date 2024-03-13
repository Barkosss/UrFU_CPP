#include<iostream>
#include<fstream>

#include "fileSystem.h"

int main() {
    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    int counter;
    readFile >> counter;
    fileSystem(readFile, writeFile, counter);

    return 0;
}