#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int m,data,n,p;
	char op;
	scanf("%d %d %d", &m, &n,&p);
	int* arr = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)arr[i] = 0;
	while (1) {
		getchar();
		scanf("%c", &op);

		if (op == 'i') {
			scanf(" %d", &data);

			int idx = data % m;
			if (!arr[idx]) {
				arr[idx] = data;
				printf("%d\n", idx);
			}
			else {
				printf("C");
				int hash = p - (data % p);
				idx = (idx+hash)%m;
				
				while (arr[idx]) {
					idx=(idx+hash)%m;
					printf("C");
				}
				arr[idx] = data;
				printf("%d\n", idx);
			}
		}
		else if (op == 's') {
			scanf(" %d", &data);
			
			int idx = data % m;
			if (arr[idx] == data) {
				arr[idx] = data;
				printf("%d %d\n", idx,data);
			}
			else {
				int hash = p - (data % p);
				idx = (idx + hash) % m;
				int cnt = 0;
				while (arr[idx]!=data && cnt !=2*m+1) {
					idx = (idx + hash) % m;
					cnt++;
				}
				if (cnt == 2*m + 1)printf("-1");
				else printf("%d %d", idx,data);
				printf("\n");
			}
			
			
		}
		else if (op == 'p') {
			for (int i = 0; i < m; i++) printf("%d ", arr[i]);
			printf("\n");
		}
		else break;
	}
	for (int i = 0; i < m; i++) printf("%d ", arr[i]);

	free(arr);
}
