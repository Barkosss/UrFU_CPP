#include<iostream>
#include<fstream>
#include<limits>
#include<string>

#include"Student.h"
#include"Date.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;

/* Формат записи
ФИО
№ Группы
Дата рождения (ДД ММ ГГГГГ)
*/

int main() {
    string findGroup, trash;

    cout << "Enter group: ";
    getline(cin, findGroup);

    ifstream readFile;
    readFile.open("students.txt", ifstream::in);

    string counterStudentsString;
    int counterStudents, indexStudent = 0;
    getline(readFile, counterStudentsString); // Считать количество студентов (Считываем из файла)
    counterStudents = stoi(counterStudentsString);
    //cout << "Counter Student: " << counterStudents << endl;
    //cout << endl;

    Student* students = new Student[counterStudents];
    string studentGroup;

    for(int index = 0; index < counterStudents; index++) {

        // ??? Чтение ФИО Студента
        getline(readFile, students[indexStudent].lastName);
        //cout << "Student name: " << students[indexStudent].lastName << endl;

        // ??? Чтение группы Студента
        getline(readFile, studentGroup);
        //cout << "Student group: " << studentGroup << endl;

        // ??? Чтение Даты рождения Студента (ДД ММ ГГГГ)
        readFile >> students[indexStudent].date.day >> students[indexStudent].date.month >> students[indexStudent].date.year;
        //cout << "Student day: " << students[indexStudent].date.day << " Day, " << students[indexStudent].date.month << " Month, " << students[indexStudent].date.year << " Year" << endl;
        readFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //cout << endl;

        // Если номер группы совпал с запрашиваемым
        //cout << studentGroup << " == " << findGroup << endl;
        if (studentGroup == findGroup) {
            indexStudent++;
        }
    }
    readFile.close();

    if (indexStudent) {
        // Сортировка студентов по дате рождения...
        Student temp;
        for (int jndex = indexStudent - 1; jndex > 0; jndex--) {
            for (int index = 0; index < jndex; index++) {
                if (students[index].date > students[index + 1].date) {
                    temp = students[index];
                    students[index] = students[index + 1];
                    students[index + 1] = temp;
                }
            }
        }

        // Вывод информации о студентах (Потом сделать вывод в файл)
        for(int index = 0; index < indexStudent; index++) {      
            unsigned short day = students[index].date.day;
            unsigned short month = students[index].date.month;
            unsigned int year = students[index].date.year;

            cout << "#" << index << " --------------------" << endl;
            cout << "Name: " << students[index].lastName << endl;
            cout << "Birthday: " << day << "." << month << "." << year << endl;
            cout << "------------------------------" << endl;
            cout << endl;
        }

        cout << "Complete!" << endl;

    } else {
        cout << "Students were not found with the specified group" << endl;
    }

    return 0;
}