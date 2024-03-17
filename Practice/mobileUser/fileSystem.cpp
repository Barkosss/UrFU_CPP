#include<iostream>
#include<fstream>
#include<string>

#include "Abonent.h"

void fileSystem(std::ifstream&readFile, std::ofstream&writeFile) {
    
    // Количество абонентов
    unsigned int counterUsers, counterDebtors = 0;
    readFile >> counterUsers;

    Abonent *users = new Abonent[counterUsers];
    Abonent *debtors = new Abonent[counterUsers];
    for(int indexUser = 0; indexUser < counterUsers; indexUser++) {
        /* ФОРМАТ ЗАПИСИ
        1. Фамилия
        2. Номер телефона
        3. Денег на счету
        */
        readFile >> users[indexUser].lastname;
        readFile >> users[indexUser].phoneNumber;
        readFile >> users[indexUser].cash;
        if (users[indexUser].cash < 0) {
            //std::cout << indexUser << " | " << users[indexUser].lastname << " | " << users[indexUser].cash << " | " << counterDebtors << std::endl;
            debtors[counterDebtors] = users[indexUser];
            counterDebtors++;
        }
    }

    if (!counterDebtors) {
        writeFile << "There are no debtors" << std::endl;
        return;
    }

    // Сортировка абонентов
    Abonent temp;
    for (int jndex = counterDebtors - 1; jndex > 0; jndex--) {
        for (int index = 0; index < jndex; index++) {
            
            if (debtors[index].cash < debtors[index + 1].cash) {
                temp = debtors[index];
                debtors[index] = debtors[index + 1];
                debtors[index + 1] = temp;
            }
        }
    }
    //std::cout << "Counter debtors: " << counterDebtors << std::endl;

    // Вывод информации
    writeFile << "№\t| Lastname\t|\tPhone\t| Cash \t\t\t|" << std::endl;
    writeFile << "----------------|-----------|---------------|" << std::endl;
    for(int indexUser = 0; indexUser < counterDebtors; indexUser++) {
        writeFile << indexUser + 1 << "\t| " << debtors[indexUser].lastname << " \t|\t" << debtors[indexUser].phoneNumber << "\t| Cash :\t" << debtors[indexUser].cash << "\t|" << std::endl;
    }

    std::cout << "Write end" << std::endl;
}