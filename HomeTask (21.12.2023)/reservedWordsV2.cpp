#include<iostream>
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
    std::ifstream reservFile("reservedwords.txt"); // Файл с зарезервированными словами (Чтение)
    string* words = new string[0];

    // Если не получилось открыть файл с зарезервированными словами
    if (!reservFile.is_open()) {
        cout << "File with reserved words not found" << endl;
        return 0;
    }

    std::ifstream textFile("text.txt"); // Файл с текстом (Чтение)
    // Если не получилось открыть файл с текстом
    if (!textFile.is_open()) {
        cout << "Text file not found" << endl;
        return 0;
    }

    // Работаем с файлом пока не дойдём до конца
    long reservLength = 0;
    //cout << "1" << endl;
    while(!reservFile.eof()) {
        reservFile >> words[reservLength];
        //cout << words[reservLength] << endl;
        reservLength++;
    }
    int* counterWords = new int[reservLength];
    for(int i = 0; i < reservLength; i++) counterWords[i] = 0;

    // Работа с файлом, в котором основной текст
    string word;
    while(!textFile.eof()) {
        textFile >> word;
        //cout << "word: " << word << endl;
        for(int i = 0; i < reservLength; i++) {
            if (word == words[i]) {
                counterWords[i]++;
            }
        }
    }

    cout << "View:" << endl;
    std::ofstream resultFile("reservedWordsResult.txt"); // Файл для результата (Запись)
    for(int i = 0; i < reservLength; i++) {
        cout << words[i] << ": " << counterWords[i] << endl;
        resultFile << words[i] << ": " << counterWords[i] << endl;
    }
    return 0;
}