#include<iostream>
#include<fstream>
#include<string>

#include "Sentence.h"

using std::string;

struct Words {
    string word;
    Words* next;
};

void toLower(string &str) {
    
    for(int index = 0; str[index]; index++) {
        str[index] = str[index] + 32 * (65 <= str[index] && str[index] <= 90);
    }
}

int main() {
    std::ifstream readFile("text.txt");

    unsigned long counterWords = 0;
    char lastChar; string word;

    while(!readFile.eof()) {
        readFile >> word;
        toLower(word);

        // ...
    }

    readFile.close();
    return 0;
}