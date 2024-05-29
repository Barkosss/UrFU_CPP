#include<iostream>
#include<fstream>
#include<string>

/*
## Total:
1. d - Неустойка за закрытие рейса, между i и j аэропортом
2. a - Плата за открытие рейса, между i и j аэропортом

## Property:
1. Рейсами Пингвин-Авиа можно добраться из любого аэропорта Антарктиды до любого другого.
Возможно, для этого придётся сделать несколько пересадок.

2. Схема должна содержать минимальное число рейсов среди всех схем, отвечающих первому свойству.  
*/


/* TODO:
1. Посмотреть видео Alek OS про графы
2. Придумать несколько графов для примеров
3. Подробно написать логику решения примеров
*/

std::ifstream readFile("input.barsik");
std::ofstream writeFile("output.barsik");

// Вершина 
struct Node {
    // Список детей у вершины
    Node* headChilds;

    Node* nextNode;
};

class Grath {
private:
    Node* headNode;
    Node* tailNode;

public:
    Grath() {};
};


int main() {
    int n;
    unsigned long long d, a;
    readFile >> n >> d >> a;

    std::string row;
    for(unsigned indexString = 0; indexString < n; indexString++) {
        readFile >> row;

        for(unsigned indexChar = 0; indexChar < n; indexChar++) {
            
        }
    }
}

/* Old code

// Convert string to matrix
void StringToMatrix(char** &matrix, std::string arrayRow[], unsigned short counter) {
    for(unsigned short index = 0; index < counter; index++) {
        for(unsigned short jndex = 0; jndex < counter; jndex++) {
            //std::cout << "StringToMatrix Convert In" << std::endl;
            matrix[index][jndex] = (int)arrayRow[index][jndex];
            //std::cout << "StringToMatrix Convert Out" << std::endl;
        }
    }
}


// ...
// ...
// ...
// ...


// Checking for the symmetrical of the matrix
bool is_symmetrical(char** const &matrix, unsigned short counter) {
    for(unsigned short index = 0; index < counter; index++) {
        for(unsigned short jndex = 0; jndex < counter; jndex++) {
            if (matrix[index][jndex] != matrix[jndex][index]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    unsigned short counterAirports;
    unsigned long long penalty, bribe;
    readFile >> counterAirports;
    readFile >> penalty >> bribe;

    char** matrix = new char*[counterAirports];
    for(unsigned short index = 0; index < counterAirports; index++) {
        matrix[index] = new char[counterAirports];
        for(unsigned short jndex = 0; jndex < counterAirports; jndex++) {
            matrix[index][jndex] = 0;
        }
    }

    // Read matrix of Fligрt (NxN)
    std::string* arrayRow = new std::string[counterAirports];
    for(unsigned short indexRow = 0; indexRow < counterAirports; indexRow++) {
        readFile >> arrayRow[indexRow];   
    }
    // Convert array of string to bool's matrix
    StringToMatrix(matrix, arrayRow, counterAirports);

    // Delete array of string
    delete[] arrayRow;


    // ...
    // ...
    /*
    TODO: В начале файла 
    
    // ...
    // ...


    // Checking for the symmetrical
    if (!is_symmetrical(matrix, counterAirports)) {
        std::cout << "The matrix is not symmetrical!" << std::endl;
        return 404; 
    }


    // Output result
    for(unsigned short index = 0; index < counterAirports; index++) {
        for(unsigned short jndex = 0; jndex < counterAirports; jndex++) {
            writeFile << matrix[index][jndex];
        }
        writeFile << std::endl;
    }

    std::cout << "Program is end" << std::endl;
    return 0;
}
*/