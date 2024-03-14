#include<iostream>
#include<fstream>
#include<string>

#include "Train.h"
#include "ConvertTimestamp.h"

void fileSystem(std::ifstream&readFile, std::ofstream&writeFile) {

    // Количество поездов
    unsigned int counterTrains;
    readFile >> counterTrains;

    // Чтение информации
    Train *trains = new Train[counterTrains];
    for(int indexTrain = 0; indexTrain < counterTrains; indexTrain++) {
        readFile >> trains[indexTrain].numberTrain;
        readFile >> trains[indexTrain].destination;
        readFile >> trains[indexTrain].timestamp;
    }

    // Сортировка поездов
    Train temp;
    for (int jndex = counterTrains - 1; jndex > 0; jndex--) {
        for (int index = 0; index < jndex; index++) {
            
            // Если пункты назначения совпадают -> Упорядочиваем по времени отправления
            if (trains[index].destination == trains[index + 1].destination) {
                
                // Если у левого дата отправления раньше, чем у правого
                if (trains[index].timestamp > trains[index + 1].timestamp) {
                    temp = trains[index];
                    trains[index] = trains[index + 1];
                    trains[index + 1] = temp;
                }
            }

            // Если наименование левого пункта больше, чем правого (Левый по алфовиту больше, чем правый)
            else if (trains[index].destination > trains[index + 1].destination) {
                temp = trains[index];
                trains[index] = trains[index + 1];
                trains[index + 1] = temp;
            }
        }
    }


    // Вывод информации
    writeFile << "Train\t|\tStation\t| Timestamp                       |" << std::endl;
    writeFile << "--------|-----------|---------------------------------|" << std::endl;
    for(int indexTrain = 0; indexTrain < counterTrains; indexTrain++) {
        writeFile << "#" << trains[indexTrain].numberTrain << "\t|\t" << trains[indexTrain].destination << "\t| Timestamp:\t" << ConvertTimestamp(trains[indexTrain].timestamp) << std::endl;
    }

    std::cout << "Write end" << std::endl;
}