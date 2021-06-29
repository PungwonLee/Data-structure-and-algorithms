#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>    // bool, true, false가 정의된 헤더 파일
#include<stdlib.h>
#include<math.h>
int* MergeFunc(int* leftArr, int* rigthArr, int leftSize, int rigthSize) {
	int* mergeArr = (int*)malloc(sizeof(int) * (leftSize + rigthSize));
	int leftidx = 0;
	int rigthidx = 0;
	int mergeidx = 0;
	while (leftSize > leftidx && rigthSize > rigthidx) {
		if (leftArr[leftidx] > rigthArr[rigthidx]) {
			mergeArr[mergeidx++] = rigthArr[rigthidx];
			rigthidx++;
		}
		else {
			mergeArr[mergeidx++] = leftArr[leftidx];
			leftidx++;
		}
	}
	while (leftSize > leftidx)
		mergeArr[mergeidx++] = leftArr[leftidx++];

	while (rigthSize > rigthidx)
		mergeArr[mergeidx++] = rigthArr[rigthidx++];

	return mergeArr;
}

int *SplitFunc(int* arr, int size) {
	if (size <= 1) return arr;

	int mid = size / 2;
	int* leftArr = (int*)malloc(sizeof(int) * mid);
	int* rightArr = (int*)malloc(sizeof(int) * (size - mid));
	
	for (int i = 0; i < mid; i++)
		leftArr[i] = arr[i];

	leftArr=SplitFunc(leftArr, mid);

	for (int i = 0; i < size-mid; i++)
		rightArr[i] = arr[i + mid];

	rightArr=SplitFunc(rightArr, size-mid);

	return MergeFunc(leftArr, rightArr, mid, size - mid);
}


int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	

	arr=SplitFunc(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	printf("\n");
}
