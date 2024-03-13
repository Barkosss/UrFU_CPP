#include<iostream>

// Получение матрицы без i-й строки и j-го столбца -> Ошибка
long double** removeItems(long double **matrix, int i, int j, int counter)  {
    int deterIndex = 0, deterJndex = 0;

    // Создание массива для новой матрицы
    long double **newMatrix = new long double*[counter];
    for(int i = 0; i < counter; i++) {
        newMatrix[i] = new long double[counter];
    }

    for(int index = 0; index < counter - 1; index++) {

        // Если индекс текущей строки, равен индексу строки, который надо вычекрнуть
        if (index == i) { // Приравниваем к единице, чтобы сделать сдвиг
            deterIndex = 1;
        }

        deterJndex = 0;
        for(int jndex = 0; jndex < counter - 1; jndex++) {
            // Если индекс текущего столбца, равен индексу столбца, которую надо вычекрнуть
            if (jndex == j) { // Приравниваем к единице, чтобы сделать сдвиг
                deterJndex = 1;
            }

            newMatrix[index][jndex] = matrix[index + deterIndex][jndex + deterJndex];
        }
    }

    return newMatrix;
}

// Нахождение определителя
long double getDeter(long double**matrix, int counter) {
    long double result = 0;
    int k = 1; // (-1) в степени i
    long double **newMatrix;

    // Если размер матрицы меньше 1
    if (counter < 1) {
        std::cout << "It is impossible to calculate the determinant!" << std::endl;
        return 0;        
    }

    // Если размер матрицы равен 1
    if (counter == 1) {
        return matrix[0][0];
    }

    // Если размер матрицы равен 2
    if (counter == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }

    // Если размер матрицы больше 2
    for(int i = 0; i < counter; i++) {
        newMatrix = removeItems(matrix, i, 0, counter);
        result = result + k * matrix[i][0] * getDeter(newMatrix, counter - 1);
        k *= -1;
    }

    // Удаляем созданный массив, чтобы очистить память
    for(int i = 0; i < counter; i++) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;
    
    std::cout << result << std::endl;
    return result;
}

long double* Kramer(long double**factors, long double*results, int counter) {

    // Результаты вычислений
    long double *unknowns = new long double[counter];

    // Определители
    long double *deter = new long double[counter];

    // Определитель
    long double currDeter;

    // Новая матрица
    long double **newDeter;

    // Номер определителя
    for(int indexDeter = 0; indexDeter <= counter; indexDeter++) {
        currDeter = 0;
        newDeter = factors;

        // Если определитель с номером больше 0
        if (indexDeter) { // Поиск определителя с заменой столбцов
            newDeter[indexDeter - 1] = results;

            // Нахождение определителя
            deter[indexDeter] = getDeter(newDeter, counter);
        }
        
        // Если определитель с номером ноль
        else { // Поиск основного определителя

            // Нахождение определителя
            deter[indexDeter] = getDeter(newDeter, counter);
        }
        //std::cout << "#" << indexDeter << ": " << deter[indexDeter] << std::endl;
    }

    // Нахождение неизвестного
    for(int indexResult = 1; indexResult <= counter; indexResult++) {
        unknowns[indexResult - 1] = deter[indexResult] / deter[0];
    }

    return unknowns;
}