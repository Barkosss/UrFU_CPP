#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void main() {
	//    ababab   asfbsdhfds     ababab - Указанная пользователь строка
	//ababab ababab - Ответ
	string str;
	cout << "Enter string: "; getline(cin, str);
	int lenStr = str.length();  int  indexStart = -1;
	cout << endl;
	cout << "DEBUG: Length original: " << lenStr << " | First symbol: " << str[0] << " | Last sybmol: " << str[lenStr - 1] << endl;
	for (int i = 0; i < lenStr; i++) {
		// Если текущий символ пробел и не был встречен пробел
		if (str[i] == ' ' && indexStart == -1) indexStart = i;
		else if (str[i] != ' ' && indexStart != -1) { // Если текущий символ не пробел и был встречен пробел
			if (indexStart == 0 || i == lenStr) { // Если пробел(-ы) в начале или конце строки
				str.replace(indexStart, i - indexStart, "");
			}
			else { // Если внутри текста пробел(-ы)
				str.replace(indexStart, i - indexStart, " ");
			}
			
			i = indexStart; // Обновляем номер индекса
			indexStart = -1; // Обнуляем индекс первого пробела
			lenStr = str.length(); // Обновляем длину строки
		}
	}
	cout << endl;
	cout << "Result: " << str << " | Length edit: " << str.length() << " | First symbol: " << str[0] << " | Last sybmol: " << str[lenStr - 1] << endl;
}