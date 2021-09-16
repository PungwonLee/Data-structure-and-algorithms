#include <stdio.h>

void rBuildHeap(int idx);
void buildHeap();

void downHeap(int idx);
void printHeap();

int n = 0, H[105];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &H[i]);
	//	buildHeap();

	rBuildHeap(1);

	printHeap();
}

void rBuildHeap(int idx) {
	if (idx > n)
		return;
	rBuildHeap(idx * 2);
	rBuildHeap(idx * 2 + 1);
	downHeap(idx);

}
void buildHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}
void downHeap(int idx) {
	if (idx * 2 > n)
		return;
	if (H[idx] < H[idx * 2] && H[idx] < H[idx * 2 + 1]) {
		if (H[idx * 2] > H[idx * 2 + 1]) {
			int tmp = H[idx];
			H[idx] = H[idx * 2];
			H[idx * 2] = tmp;
			downHeap(idx * 2);
		}
		else {
			int tmp = H[idx];
			H[idx] = H[idx * 2 + 1];
			H[idx * 2 + 1] = tmp;
			downHeap(idx * 2 + 1);
		}
	}

	if (H[idx] < H[idx * 2]) {
		int tmp = H[idx];
		H[idx] = H[idx * 2];
		H[idx * 2] = tmp;
		downHeap(idx * 2);
	}
	if (H[idx] < H[idx * 2 + 1]) {
		int tmp = H[idx];
		H[idx] = H[idx * 2 + 1];
		H[idx * 2 + 1] = tmp;
		downHeap(idx * 2 + 1);
	}


}
void printHeap() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", H[i]);
	}
	printf("\n");
}
