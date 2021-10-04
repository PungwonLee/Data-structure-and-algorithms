#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void inPlaceQuickSort(int* L, int l, int r);
int findPivot(int* L, int l, int r);
int inPlacePartition(int* L, int l, int r, int k);
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	inPlaceQuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)printf("%d ", arr[i]);

	free(arr);
}

void inPlaceQuickSort(int* L, int l, int r) {
	if (l >= r)
		return;
	int k = findPivot(L, l, r);
	int i=inPlacePartition(L, l, r, k);
	inPlaceQuickSort(L, l, i - 1);
	inPlaceQuickSort(L, i + 1, r);

}
int findPivot(int* L, int l, int r) {
	return rand() % (r - l+1) + l;
}
int inPlacePartition(int* L, int l, int r, int k) {
	int p = L[k];
	int tmp = L[k];
	L[k] = L[r];
	L[r] = tmp;

	int i = l;
	int j = r - 1;
	
	while (i <= j) {
		while (i <= j && L[i] <= p)
			i++;
		while (j >= i && L[j] >= p)
			j--;
		if (i < j) {
			tmp = L[i];
			L[i] = L[j];
			L[j] = tmp;
		}		
	}
	 tmp = L[i];
	L[i] = L[r];
	L[r] = tmp;
	return i;
}
