#include<iostream>
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


// Конец предложения: .!?;:()
// Слова состоят из букв или символа ' (аостроф)
// Слова отделены людыми другими символами

/* Примерная логика алгоритма

### 1. Чтение файла
Для начала мы читаем весь текст из файла целиком

## 2. Разбиение текст на предложения
Формируем массив из предложений, который мы потом передаём в функцию,
которая будет брать элемент массива и разбивать строку на отдельные слова,
чтобы потом передать массив слов в другую функцию, которая создаст ссылку на новое преложение
и будет последовательно добавлять новые слова в это предложение

Повторяем 2 пункт до тех пор, пока не пройдём весь массив

*/

// Является ли символ концом предложения
bool isEndSentence(char _char) {
    return _char == '.' || _char == '!' || _char == '?' || _char == ';' || _char == ':' || _char == '(' || _char == ')';
}

// Является ли символ концом слова
bool isEndWord(char _char) {
    return !(129 <= tolower(_char) <= 154) || _char != 71;
}

struct Word {
    string word;

    Word* nextWord;
};

struct Sentence {
    string sentence;
    Word* firstWord;
    Word* lastWord;
    
    Sentence* nextSentence;
    Sentence(string sentence): sentence(sentence) {};
    bool is_empty_sentence() {
        return firstWord == nullptr;
    }
    void push(string word) {
        // ...
    }
};

class Text {
    Sentence* firstSentence;
    Sentence* lastSentence;
public:
    bool is_empty_text() {
        return firstSentence = nullptr;
    }
    void push(string sentence) {
        Sentence *ptrSentence = new Sentence(sentence);
        
    }
};


int main() {
    ifstream readFile("text.txt");

    if (!readFile.is_open()) return 404;

    string text, sentence = "";

    // Чтение всего файла
    while(!readFile.eof()){
        getline(readFile, sentence);
        text += sentence;
        if (!readFile.eof()){
            text += '\n';
        }
    }
    readFile.close();

    Text _text = Text();
    unsigned long long lengthText = text.length();
    for(unsigned long long index = 0; index < lengthText; index++) {
        // Если конец предложения
        if (isEndSentence(text[index])) {
            _text.push(sentence);
            sentence = "";
            index++;
        } else {
            sentence += text[index];
        }
    }
    return 0;
}

/*
// ---- Создание массива ----
struct Node {
    string word;
    Node *next;

    Node(string word): word(word) {};
};

class Vector {
private:
    Node *first;
    Node *last;
    unsigned long counter;

public:
    Vector(): first(nullptr), last(nullptr), counter(0) {};

    // Проверка, пустой ли список или нет
    bool is_empty() {
        return first == nullptr;
    }

    // Добавить строку в список
    void push(string word) {
        Node* ptr = new Node(word);
        if (is_empty()) {
            first = ptr;
            last = ptr;
            return;
        }
        counter++;
        last->next = ptr;
        last = ptr;
    }

    // Получить массив строк
    string getArray() {
        string* array = new string[counter];
        Node* ptr = first;
        for(unsigned long index = 0; index < counter; index++) {
            array[index] = ptr->word;
            ptr = ptr->next;
        }
        return *array;
    }

    // Получить длину списка
    unsigned long getLength() {
        return counter;
    }
};
// ---- Создание массива ----


struct Words {
    string word;

    Words *nextWord;
    Words *prevWord;
};

struct Sentences {
    Words *firstWord;
    Words *lastWord;

    unsigned long counterWords;
    Sentences *nextSentences;
    Sentences *prevSentences;

public:
    Sentences(): firstWord(nullptr), lastWord(nullptr) {};

    // Проверить, пустое ли предложение
    bool sentence_is_empty() {
        return firstWord == nullptr;
    }

    // Добавить слово в предложение
    void pushWord(string word) {

    }
};

class List {
private:
    Sentences *firstSentences;
    Sentences *lastSentences;

    unsigned long counterSentences;

public:
    List(): firstSentences(nullptr), lastSentences(nullptr) {};
    
    // Пустой ли текст
    bool text_is_empty() {
        return firstSentences == nullptr;
    }

    // Создать предложение со словами
    void pushSentence(string words, unsigned long counterWords) {

    }

    // Конвертировать текст в предложения
    void convertToSentences(string text) {
        unsigned long long lengthText = text.length();
        unsigned long counterSentences = 0;
        Vector vectorSentences = Vector();
        string sentences = "";
        for(int indexChar = 0; indexChar < lengthText; indexChar++) {
            // Если конец предложения
            if (text[indexChar] == '.' || text[indexChar] == '!' || text[indexChar] == '?' || text[indexChar] == ';' || text[indexChar] == ':' || text[indexChar] == '(' || text[indexChar] == ')') {
                vectorSentences.push(sentences);
                counterSentences++;

            } else {
                sentences += text[indexChar];
            }
        }

        string arraySentences = vectorSentences.getArray();
    }
};

int main() {
    ifstream textFile("text.txt");
    string text, sentence;

    // Чтение всего файла
    while(!textFile.eof()){
        getline(textFile, sentence);
        text += sentence;
        if (!textFile.eof()){
            text += '\n';
        }
    }
    textFile.close();
    
    List listText = List();
    listText.convertToSentences(text);

    return 0;
}
*/