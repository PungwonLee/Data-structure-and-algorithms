#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	char data;
	struct Node* word[26]; //26개의 포인터 정적배열 
}Node;
Node* initNode();//node의 초기화 함수
void makeInNode(Node* v, char* tmp, int idx);
void FreeNode(Node* v);

int main() {
	Node* root = initNode(); //root에 노드를 만든다.
	int n;
	char data[101];
	scanf("%d", &n);
	while (n--) {					//n만큼 반복
		getchar();
		scanf("%s", data);			//문자 입력
		makeInNode(root, data, 0);
	}
	scanf("%d", &n);
	while (n--) {
		getchar();
		scanf("%s", data);
		Node* it = root->word[data[0] - 'A'];	// it를 선언해 root의 data[0] 주소를 저장한다
		int i = 1;							//문자열 읽기위해 사용
		while (it != NULL) {				//it가 NULL일때까지 반복한다.
			printf("%c", it->data);			//해당 하는 노드의 data를 출력
			it = it->word[data[i] - 'A'];	//다음 노드로 이동한다.
			i++;
		}
		printf("\n");
	}
	FreeNode(root); //모든 노드들을 동적 해제하는 함수를 호출
	
}
Node* initNode() {	//node의 초기화 함수
	Node* node = (Node*)malloc(sizeof(Node));
	for (int i = 0; i < 26; i++)
		node->word[i] = NULL;

	return node;
}
void FreeNode(Node* v) {

	for (int i = 0; i < 26; i++) //배열당 26개가 있기때문에 26번 반복
		if(v->word[i])	//할당된 배열만 실행
			FreeNode(v->word[i]);	//FreeNode호출

	if (v)			//NULL이 아닐때 실행
		free(v);	//해당 노드 동적 해제

}
void makeInNode(Node* v, char* tmp, int idx) {		//노드를 만드는 함수

	if (!tmp[idx]) return;					//입력받은 문자열이 끝나면  return 하여 종료한다.
	if (v->word[tmp[idx] - 'A'] == NULL) {	//노드에 해당하는 문자가 없으면 실행
		v->word[tmp[idx] - 'A'] = initNode();	//노드를 생성한다.
		v->word[tmp[idx] - 'A']->data = tmp[idx];	//data에 문자를 저장한다.
	}
		makeInNode(v->word[tmp[idx] - 'A'], tmp, idx + 1); // 다음 노드 tmp[idx]로 이동한다 
														   //idx+1하여 다음 문자로 이동한다.

	
}
