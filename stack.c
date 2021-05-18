#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void push(char* stack, char data, int* top, int* size);
char pop(char* stack, int* top);
void peek(char* stack, int* top);
void duplicate(char* stack, int* top, int* size);
void upRotate(char* stack,int n_op,int *top);
void downRotate(char* stack, int n_op, int* top);
void print(char* stack, int* top, int* size);
int main() {
	int n, size,n_op,top=-1;
	char* stack, op[10],data;
	scanf("%d%d", &size, &n);
	stack = (char*)malloc(size * sizeof(char));
	while (n--) {
		getchar();
		scanf("%s",op);
		if (strcmp(op, "PUSH") == 0) {
			scanf(" %c",&data);
			push(stack, data, &top, &size);
		}
		else if (strcmp(op, "POP") == 0)
			pop(stack, &top);
		else if (strcmp(op, "PEEK") == 0) 
			peek(stack, &top);
		else if (strcmp(op, "DUP") == 0)
			duplicate(stack, &top, &size);
		else if (strcmp(op, "UpR") == 0) {
			scanf(" %d", &n_op);
			upRotate(stack, n_op, &top);
		}
		else if (strcmp(op, "DownR") == 0) {
			scanf(" %d", &n_op);
			downRotate(stack, n_op,&top);
		}
		else if (strcmp(op, "PRINT") == 0)
			print(stack, &top, &size);
	}
	free(stack);
}
void push(char* stack, char data, int* top, int* size) {
	if (*top >= *size - 1) { return printf("Stack FULL\n"); }
	stack[++(*top)] = data;
}
char pop(char* stack, int* top) {
	if (*top < 0) { return printf("Stack Empty\n"); }
	return stack[(*top)--];
}
void peek(char* stack, int* top) {
	if (*top < 0) { return printf("Stack Empty\n"); }
	printf("%c\n",stack[*top]);
}
void duplicate(char* stack, int* top, int* size) {
	if (*top >= *size - 1) { return printf("Stack FULL\n"); }
	char tmp = pop(stack, top);
	push(stack, tmp, top, size);
	push(stack, tmp, top, size);
}
void upRotate(char* stack, int n_op, int* top) {
	if (n_op-1 > *top)return;
	char tmp = stack[*top];
	for (int i = (*top); i >= *top-n_op+1; i--) 
		stack[i] = stack[i-1];
	stack[*top-n_op+1] = tmp;
}
void downRotate(char* stack, int n_op, int* top) {
	if (n_op - 1 > *top)return;
	char tmp = stack[*top-n_op+1];
		for (int i = *top-n_op+1; i < *top ; i++) 
		stack[i] = stack[i+1];
	stack[*top] = tmp;
}
void print(char* stack, int* top, int* size) {
	int tmp = *top;
	while (tmp != -1) {
		peek(stack, &tmp);
		tmp--;
	}
	printf("\n");
}
