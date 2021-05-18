#include <stdio.h>
#include <stdlib.h>

int isfull(int* q, int* front, int* rear, int* size);
int isempty(int* q, int* front, int* rear, int* size);
void enqueue(int* q, int data, int* front, int* rear, int* size);
void dequeue(int* q,int* front, int* rear, int* size);
void print(int* q, int* size);

int main() {
	int size, *q, n, data, front = 1, rear;
	char op;
	scanf("%d %d", &size,&n);
	
	rear = 0;
	
	q = (int*)malloc((size)*sizeof(int));
	for (int i = 0; i < size; i++)q[i] = 0;
	while (n--) {
		getchar();
		scanf("%c", &op);
		if (op == 'I') {
			scanf(" %d", &data);
			enqueue(q, data,&front, &rear, &size);
		}
		else if (op == 'D')
			dequeue(q, &front, &rear, &size);

		else if (op == 'P')
			print(q, &size);
	}
	free(q);
}

int isfull(int* q, int* front, int* rear, int* size) {
	return (*rear + 2) % *size == *front;
}
int isempty(int* q, int* front, int* rear, int* size) {
	return (*rear+1) % *size == *front;
}
void enqueue(int* q, int data, int* front, int* rear, int* size) {
	if (isfull(q, front, rear, size))
		return printf("overflow"),print(q,size),exit(0);
	*rear = (*rear + 1) % *size;
	q[*rear] = data;
}
void dequeue(int* q, int* front, int* rear, int* size) {
	if (isempty(q, front, rear, size))
		return printf("underflow\n"),exit(0);
	q[*front] = 0;
	*front = (*front + 1) % *size;
}
void print(int* q, int* size) {
	for (int i = 0; i < *size; i++)
		printf(" %d", q[i]);
	printf("\n");
}
