#include<fstream>

#include "fileSystem.h"

/*
Написать класс, моделирующий многоугольники, возможно
невыпуклые. С его помощью решить следующую задачу: для
многоугольников, заданных в файле, вычислить площадь и выписать
их в новый файл, упорядочив по убыванию площади.
*/

int main() {
    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    fileSystem(readFile, writeFile);
    return 0;
}