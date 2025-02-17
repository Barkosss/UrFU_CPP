#include<iostream>
#include<fstream>
#include<vector>
#include<numeric>

/*
В массиве из N целых чисел найти все k-элементные подмножества,
состоящие из попарно взаимно простых чисел
*/

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::gcd;
using std::ifstream;
using std::ofstream;

ofstream outFile("outputIndiv2.txt");


bool isPairwiseCoprime(const vector<int> &subset) {
    for (size_t i = 0; i < subset.size(); ++i) {
        for (size_t j = i + 1; j < subset.size(); ++j) {
            if (gcd(subset[i], subset[j]) != 1) {
                return false;
            }
        }
    }
    return true;
}


void findCoprimeSubsets(const vector<int> &array, vector<int> &currentSubset, int k, int index) {
    if (currentSubset.size() == k) {
        if (isPairwiseCoprime(currentSubset)) {
            for (int num : currentSubset) {
                outFile << num << " ";
            }
            outFile << endl;
        }
        return;
    }

    for (size_t i = index; i < array.size(); ++i) {
        currentSubset.push_back(array[i]);
        findCoprimeSubsets(array, currentSubset, k, i + 1);
        currentSubset.pop_back();
    }
}


int main() {
    ifstream inFile("inputIndiv2.txt");

    if (!inFile.is_open()) {
        cout << "File \"input.txt\" is not found" << endl;
        return 404;
    }
    int counter;
    inFile >> counter;

    for (int index = 0; index < counter; index++) {
        int N, k;
        inFile >> N;
        vector<int> array(N);

        for (int i = 0; i < N; ++i) {
            inFile >> array[i];
        }

        inFile >> k;
        vector<int> currentSubset;
        outFile << "Pairwise mutually simple subsets of size " << k << ":" << endl;
        findCoprimeSubsets(array, currentSubset, k, 0);
        outFile << endl;
    }
    return 0;
}