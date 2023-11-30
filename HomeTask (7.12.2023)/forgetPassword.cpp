#include<iostream>
#include<string>
#include<cmath>

using std::string;
using std::cin;
using std::cout;
using std::endl;

bool flag = false;

// Функция для создания пароля
string createPassword(string password) {
    
}

int main() {

    string oldPassword;
    cout << "Enter old password: "; std::getline(cin, oldPassword);
    long lenString = oldPassword.length(); // Длина строки
    
    createPassword(oldPassword);

    return 0;
}