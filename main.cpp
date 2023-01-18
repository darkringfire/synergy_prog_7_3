#include <iostream>
#define N 3

bool isSquare(int x) {
    int b = x;
    int a;
    do {
        a = b;
        b = (a + x / a) / 2;
    } while (b < a);
    return a * a == x;
}

int countSquares(int a[], int size) {
    int n = 0;
    for (int i = 0; i < size; i++) {
        if (isSquare(a[i])) {
            n++;
        }
    }
    return n;
}

void countSquares(int a[], int size, int &n) {
    n = countSquares(a, size);
}

void countSquares(int a[], int size, int *n) {
    *n = countSquares(a, size);
}

int main() {
    int arr[N];
    for (int i = 0; i < N; i++) {
        printf("Enter item %i:", i);
        scanf("%i", &arr[i]);
    }

    int n;

    n = countSquares(arr, N);
    printf("Get via return: %i\n", n);

    countSquares(arr, N, n);
    printf("Get via reference: %i\n", n);

    countSquares(arr, N, &n);
    printf("Get via pointer: %i\n", n);


    return 0;
}
