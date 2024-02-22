#pragma once
using std::ifstream;
using std::ofstream;

void ReadMatrix(ifstream&readFile, ofstream&writeFile);
void SmoothingMatrix(long sizeOfMatrix, long double **matrix, ofstream&writeFile);
void WriteMatrix(long sizeOfMatrix, long double **matrix, long double sumMainDiagonal, ofstream&writeFile);