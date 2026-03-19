/*
Вариант 21.
Вас попросили написать программу «Контентный фильтратор». Работает она
очень просто: есть несколько запрещенных слов, если в тексте присутствует
запрещенное слово, то оно заменяется таким количеством символов *, сколько
букв в этом слове.
*/


#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    string text;
    printf("Введите текст: ");
    getline(cin, text);

    int badCount;
    printf("Количество слов: ");
    scanf_s("%d", &badCount);
    getchar();

    string* badWords = new string[badCount];

    for (int i = 0; i < badCount; i++) {
        getline(cin, badWords[i]);
    }


    string filtered = text;
    string lowerText = text;
    for (int i = 0; i < text.length(); i++) {
        lowerText[i] = tolower(text[i]);
    }

    for (int i = 0; i < badCount; i++) {
        string lowerWord = badWords[i];
        for (int j = 0; j < lowerWord.length(); j++) {
            lowerWord[j] = tolower(lowerWord[j]);
        }

        int pos = 0;
        while ((pos = lowerText.find(lowerWord, pos)) != string::npos) {
            if (((pos == 0 || (lowerText[pos - 1] == ' '))) && (pos + lowerWord.length() >= lowerText.length() || lowerText[pos + lowerWord.length()] == ' ')) {
                filtered.replace(pos, lowerWord.length(), string(lowerWord.length(), '*'));
                lowerText.replace(pos, lowerWord.length(), string(lowerWord.length(), '*'));
            }
            pos += lowerWord.length();
        }
    }

    printf("Результат: %s\n", filtered.c_str());
    return 0;
}
