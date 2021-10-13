#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	struct Node* left, * rigth;
	int data;
}Node;
void rBuildHeap(Node* root);
Node* ListToTree(Node* root, int* arr, int idx, int n);
void TreeToListAndFree(Node* root, int* arr, int idx, int n);
Node* initNode(int k);
void downHeap(Node* v);
int main() {
	Node* root = NULL;
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc((n + 1) * sizeof(int));

	for (int i = 1; i <= n; i++) 
		scanf("%d", &arr[i]);
	
	root = ListToTree(root, arr, 1, n);  //배열을 트리로 만든다

	rBuildHeap(root); //상향식 힙 생성 함수 실행

	TreeToListAndFree(root, arr, 1, n); //트리를 배열에 저장하면서 메모리해제한다.

	for (int i = 1; i <= n; i++)  //배열 출력
		printf("%d ", arr[i]);
	
	free(arr); //배열 메모리 해제
}
Node* ListToTree(Node* root, int* arr, int idx, int n) {
	if (idx <= n) {
		root = initNode(arr[idx]); // 노드 초기화 동시 값을 저장한다.

		root->left = ListToTree(root->left, arr, idx * 2, n); //left노드로 이동한다
		root->rigth = ListToTree(root->rigth, arr, idx * 2 + 1, n); //rigth 노드로 이동한다.
	}
	return root;  
}
void TreeToListAndFree(Node* root, int* arr, int idx, int n) {
	if (idx <= n) {
		arr[idx] = root->data;   //트리의 데이터를 배열에 저장한다
		TreeToListAndFree(root->left, arr, idx * 2, n);   //left노드로 이동한다
		TreeToListAndFree(root->rigth, arr, idx * 2 + 1, n); //rigth노드로 이동한다.
		free(root); //값을 배열에 옮겼으므로 메모리해제한다.
	}
}

void rBuildHeap(Node* v) {
	if (v) {				//v가 NULL이아니면 실행한다
		rBuildHeap(v->left);		//v의 left노드로 힙생성
		rBuildHeap(v->rigth);		//v의 rigth노드로 힙생성
		downHeap(v);				//downHeap 호출
	}
}
void downHeap(Node* v) {
	if (v->left == NULL)return;  // left가 없으면 rigth도 없기때문에 리턴한다
	Node* max = v->left;		// 자식노드 중 큰 것을 고르기위해 max에 일단 left를 저장한다.
	if (v->rigth) {				//rigth가 있을때만 실행한다 
		if (v->rigth->data > max->data) //max에 저장된 left보다 rigth가 더 높을 시 실행하며
			max = v->rigth;					//max에 rigth를 저장한다.
	}

	if (v->data < max->data) {	// max가 v보다 크면 실행하며
		int tmp = v->data;
		v->data = max->data;		//tmp임시변수를 이용하여 v의 데이터와 max 데이터를 스왑한다.
		max->data = tmp;
	}
	downHeap(max); //다음 자식 노드로 downHeap을 호출한다.
}
Node* initNode(int k) {			
	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->rigth = NULL;					//노드생성후 초기화해준다
	node->data = k;						//값을 저장한다.
	return node;
}
