#include<iostream>
#include<fstream>
#include<string>

#include "Sentence.h"

int main() {
    std::ifstream readFile("text.txt");
    std::string fullText = "";
    std::string readText;
    while(readFile >> readText) {
        fullText += readText;
    }

    Sentence text;
    

    readFile.close();
    return 0;
}