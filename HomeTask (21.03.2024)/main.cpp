#include<iostream>
#include<fstream>

#include "fileSystem.h"

int main() {
    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    fileSystem(readFile, writeFile);

    readFile.close();
    writeFile.close();
    return 0;
}