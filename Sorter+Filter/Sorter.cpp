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