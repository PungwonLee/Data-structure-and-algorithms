#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>    // bool, true, false가 정의된 헤더 파일
#include<stdlib.h>
#include<math.h>
//https://visualgo.net/en/sorting 각 정렬의 영상.

void BubleSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		bool swap = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) { //오름차순이며 내림차순은 > 로 바꾸면 된다.
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swap = true;
			}
		}
		if (swap == false) //swap이 false이면 정렬이 완료됐으므로 종료한다.
			break;
	}
}
void SelectionSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}
void InsertSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			else break;
		}
	}
}
int main() {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = rand()%10;
	}
	InsertSort(arr, 100);
	for (int i = 0; i < 100; i++) {
		printf("%d\n", arr[i]);
	}
}
