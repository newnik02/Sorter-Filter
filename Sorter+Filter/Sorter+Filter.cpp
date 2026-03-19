/*
* Вариант 21.
Дан массив из N элементов. Вводится число K – количество блоков (K<<N).
Упорядочить элементы по возрастанию в каждом блоке.
*/

#include <iostream>
using namespace std;

void sortBlock(int arr[], int blockStart, int blockEnd) {
    int size = blockEnd - blockStart;
    for (int a = blockStart; a < blockEnd; a++) {
        for (int b = blockEnd - 1; b >= a; b--) {
            if (arr[b - 1] > arr[b]) {
                int t = arr[b - 1];
                arr[b - 1] = arr[b];
                arr[b] = t;
            }
        }
    }
}

void main() {
    setlocale(LC_ALL, "");
    int N, K;

    printf("Введите размер массива N: ");
    scanf_s("%d", &N);

    int* arr = new int[N];

    printf("Введите %d элементов массива:\n", N);
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("Введите количество блоков K: ");
    scanf_s("%d", &K);

    int division = N / K;
    int remainder = N % K;
    int blockStart = 0;
    int blockSize = 0;

    for (int i = 0; i < K; i++) {

        if (remainder > 0) {
            blockSize = division + 1;
            remainder -= 1;
        }
        else {
            blockSize = division;
        }

        sortBlock(arr, blockStart + 1, blockStart + blockSize);
        blockStart += blockSize;

    }

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
}

/*
Вариант 21.
Вас попросили написать программу «Контентный фильтратор». Работает она
очень просто: есть несколько запрещенных слов, если в тексте присутствует
запрещенное слово, то оно заменяется таким количеством символов *, сколько
букв в этом слове.
*/

/*
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
*/