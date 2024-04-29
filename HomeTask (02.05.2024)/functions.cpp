// Programm for first task
#include<iostream>
#include<fstream>
#include<string>

int getLength() {
    return 5;
}

int getRandomNumber() {
    return -1;
}

std::string getAnswer() {
    return "";
}

std::string getAge() {
    return "";
}

long long getPhoneNumber(int number) {
    if (!number) return number;

    return getPhoneNumber(number - 1);
}

std::string getSchool() {
    return "";
}

std::string getName() {
    return "";
}

int main() {
    int number;
    std::cin >> number;
    std::cout << "Answer" << std::endl;
    getLength();

    getRandomNumber();
    getPhoneNumber(number);
    getAnswer();

    return 0;
}