#include<iostream>
#include<fstream>
#include<vector>

/*
Задано множество из n целых чисел.
Сформировать и вывести все подмножества заданного множества.
*/

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    long value;
    vector<long> arr;
    while(!inFile.eof()) {
        inFile >> value;
        arr.push_back(value);
    }

    vector<vector<long>> subArr;
    unsigned long size = arr.size();
    for(unsigned long index = 0; index < size; index++) {
        vector<long> set;
        for(unsigned long jndex = index; jndex < size; jndex++) {
            set.push_back(arr[jndex]);
            subArr.push_back(set);
        }
        set.clear();
    }

    unsigned long subArrSize = subArr.size(), setSize;
    for(unsigned long index = 0; index < subArrSize; index++) {
        setSize = subArr[index].size();
        outFile << "#" << index << ": ";
        for(unsigned jndex = 0; jndex < setSize; jndex++) {
            outFile << subArr[index][jndex] << " ";
        }
        outFile << endl;
    }
    cout << "Program is done!" << endl;

    return 0;
}