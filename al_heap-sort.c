#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>    // bool, true, false가 정의된 헤더 파일
#include<stdlib.h>
#include<math.h>
#include <stdio.h>

void inPlaceHeapSort();
void buildHeap();
void insertItem(int key);

void rBuildHeap(int idx);

void upHeap(int idx);
void downHeap(int i, int last);
void printHeap();

void swap(int idx);
void downHeap2(int idx);
int n = 0, H[105];


int main() {
	
	//	buildHeap();

	inPlaceHeapSort();

	printHeap();
}
void inPlaceHeapSort() {
	buildHeap();

	//printf("%d\n",n);
	//printHeap();
	for (int i = n; i >= 2; i--) {
		int tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		downHeap(1,i-1);
	}
}
void rBuildHeap(int idx) {
	if (idx > n)
		return;
	rBuildHeap(idx * 2);
	rBuildHeap(idx * 2 + 1);
	downHeap(idx,n);

}
void buildHeap() {
	int key,m;
	scanf("%d", &m);
	for (int i = 1; i <=m; i++) {

		scanf("%d", &key);
		insertItem(key);
	}
}

void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
}
void upHeap(int idx) {
	if (idx <= 1)
		return;
	if (H[idx] <= H[idx / 2])
		return;
	int tmp = H[idx];
	H[idx] = H[idx / 2];
	H[idx / 2] = tmp;
	upHeap(idx / 2);
}
void downHeap(int i,int last) {
	//printHeap();
	int l = 2 * i;
	int r = 2 * i+1;
	if (l > last) return;
	
	int g = l;
	if (r <= last) {
		if (H[r] > H[g])
			g = r;
	}

	if (H[i] >= H[g])
		return;
	int tmp = H[i];
	H[i] = H[g];
	H[g] = tmp;
	downHeap(g, last);



}
void printHeap() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", H[i]);
	}
	printf("\n");
}



/*
8
5 15 10 20 30 25 31 29
i 15
i 10
i 20
i 30
i 25
p
d
i 31
i 29
d
p

*/
