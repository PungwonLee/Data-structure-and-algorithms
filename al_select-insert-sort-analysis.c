#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
int* insertSort(int[], int);
int* selectSort(int[], int);
int* reversInsertSort(int arr[], int n);
int main() {
    int* X, n, * A, N;

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    scanf("%d", &n);
    N = n;
    X = (int*)malloc(n * sizeof(int));
    

    printf("select random\n");
    for (int i = 0; i < 10; i++) {

        for (int i = 0; i < n; i++)
            X[i] = (rand() % N / 10 * (i + 1)) + 1;
        n = N / 10 * (i + 1);
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        //측정시작
        A = selectSort(X, n);

        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("%d : %lf sec\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
    }

    printf("\n");
    

    
    printf("\ninsert random\n");
    for (int i = 0; i < 10; i++) {
    for (int i = 0; i < n; i++)
            X[i] = (rand() % N / 10 * (i + 1)) + 1;
        n = N / 10 * (i + 1);
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        //측정시작
        A = insertSort(X, n);

        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("%d : %lf sec\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    }

    printf("\n");

    printf("\nselect sort\n");
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < n; i++)
            X[i] = (rand() % N / 10 * (i + 1)) + 1;
        n = N / 10 * (i + 1);
        insertSort(X, n);//한번 정렬
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        //측정시작
        A = selectSort(X, n);

        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("%d : %lf sec\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    }

    printf("\n");

    printf("\ninsert sort\n");
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < n; i++)
            X[i] = (rand() % N / 10 * (i + 1)) + 1;
        n = N / 10 * (i + 1);
        insertSort(X, n);  //한번 정렬

        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        //측정시작
        A = insertSort(X, n);

        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("%d : %lf sec\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    }

    printf("\n");


    printf("\nselect revers sort\n");
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < n; i++)
            X[i] = (rand() % N / 10 * (i + 1)) + 1;
        n = N / 10 * (i + 1);
        reversInsertSort(X, n);  //한번 역순으로 정렬
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        //측정시작
        A = selectSort(X, n);

        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("%d : %lf sec\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    }

    printf("\n");

    printf("\ninsert revers sort\n");
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < n; i++)
            X[i] = (rand() % N / 10 * (i + 1)) + 1;
        n = N / 10 * (i + 1);
        reversInsertSort(X, n);  //한번 역순으로 정렬
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        //측정시작
        A = insertSort(X, n);

        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("%d : %lf sec\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

    }
    
}

int* insertSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            j--;
        }
    }
    return arr;
}
int* selectSort(int arr[], int n) {
  
    for (int i = n - 1; i > 0; i--) {
        int max_idx = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[max_idx] < arr[j])
                max_idx = j;
        }
        int tmp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = tmp;

    }
    return arr;
}

int* reversInsertSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (j >= 0 && arr[j] < arr[j + 1]) {
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            j--;
        }
    }
    return arr;
}
