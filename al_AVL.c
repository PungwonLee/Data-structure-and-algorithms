#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node* parent, * l, * r;
	int key, h;
}Node;
int findElement(Node* v, int k);
void insertItem(Node** v, int k);
Node* treeSearch(Node* v, int k);
int removeElement(Node** v, int k);

int isExternal(Node* v);
int  isInternal(Node* v);
Node* sibling(Node* w);
Node* inOrderSucc(Node* w);
Node* reduceExternal(Node** z);
Node* initNode();
void freeTree(Node* v);
void printTree(Node* v);

void searchAndFixAfterInsertion(Node* v, Node** r);
int updateHeight(Node* v);
int isBalanced(Node* v);
Node* restructure(Node* x, Node* y, Node* z, Node** r);

void searchAndFixAfterRemoval(Node* v, Node** r);
int main() {
	Node* root = initNode();
	char op;
	int k;
	while (1) {
		scanf("%c", &op);
		if (op == 'i') {
			scanf(" %d", &k);
			insertItem(&root, k);
		}
		else if (op == 's') {
			scanf("%d", &k);
			int res = findElement(root, k);
			if (res != 0) printf("%d\n", res);
			else printf("X\n");
		}
		else if (op == 'd') {
			scanf("%d", &k);
			int res = removeElement(&root, k);
			if (res != 0)printf("%d\n", res);
			else printf("X\n");
		}
		else if (op == 'p') {
			printTree(root);
			printf("\n");
		}
		else break;
		getchar();
	}
	freeTree(root);
}

Node* treeSearch(Node* v, int k) {
	if (isExternal(v)) return v;  //외부노드면 반환한다.
	if (k == v->key) return v; //v의 key값이 k이면 반환한다.
	else if (k < v->key) return treeSearch(v->l, k);
	else return treeSearch(v->r, k);				//모든 트리를 탐색한다.
}
void insertItem(Node** v, int k) {

	Node* w = treeSearch(*v, k);  //k값인 노드를 반환한다.
	if (isInternal(w)) return;  //내부노드면 이미 k값이 존재하기 때문에 함수를 종료한다.
	else {
		w->key = k;			
		w->l = initNode();
		w->r = initNode();
		w->l->parent = w;
		w->r->parent = w;
		w->h = 0;
		//72~77 key값을 넣고 left rigth 자식을 초기화한다.
		updateHeight(*v);		//root부터 높이를 갱신한다.
		searchAndFixAfterInsertion(w, v);

	}
}
int findElement(Node* v, int k) {
	Node* w = treeSearch(v, k);			//k값에 해당하는 노드를 반환한다.
	if (isInternal(w)) return w->key; // 내부노드면 k값이 있으므로 k값을 반환한다.
	else return 0;				//값이 없는 노드므로 0을 반환한다.
}
int isExternal(Node* v) {		//외부노드 인지 확인하는 함수이다
	if (v->l == NULL && v->r == NULL) return 1;
	else return 0;
}
int  isInternal(Node* v) {		//내부노드 인지 확인하는 함수이다
	if (v->l != NULL && v->r != NULL)return 1;
	else return 0;
}


Node* reduceExternal(Node** z) {
	Node* w = (*z)->parent;   //w에 z의 부모를 저장한다.
	Node* zs = sibling((*z)); //z의 형제를 zs에 저장한다.

	if (w->parent == NULL) {	//w가 root면 실행한다.
		*w = *zs;				//root를 zs로 지정한다.
		zs->parent = NULL;     //root 이므로 부모는 NULL
	}
	else {
		Node* g = w->parent;  //g에 w의 부모를 저장한다.
		zs->parent = g;		//zs부모를 g로 지정한다.
		if (w == g->l)		//왼쪽 오른쪽 자식인지 구분한다.
			g->l = zs;
		else
			g->r = zs;
	}
	free(*z);		
	if (zs->parent != NULL) free(w);		//노드를 해제한다.
	return zs;

}

Node* sibling(Node* w) {			//형제 노드를 찾는 함수.
	if (w->parent->l == w)
		return w->parent->r;
	else
		return w->parent->l;
}
Node* inOrderSucc(Node* w) {		//중위 후계자 찾는 함수
	w = w->r;
	while (isInternal(w->l))	//내부노드면 왼쪽자식으로 이동을 반복한다.
		w = w->l;
	return w;
}

void printTree(Node* v) {		//전위 순회로 출력 하는 함수
	if (isInternal(v)) {
		printf(" %d", v->key);
		printTree(v->l);
		printTree(v->r);
	}
}
void freeTree(Node* v) {		//트리 메모리 해제 함수.
	if (v) {
		freeTree(v->l);
		freeTree(v->r);
		free(v);
	}
}
Node* initNode() {					//노드 초기화 함수
	Node* node = (Node*)malloc(sizeof(Node));
	node->l = node->r = node->parent = NULL;
	node->h = 1;
	node->key = 0;
	return node;
}
void searchAndFixAfterInsertion(Node* w, Node** r)
{
	Node* x, * y, * z;
	z = w;
	while (z != NULL) {		//루트까지 올라가면서 불균형 노드를 찾는 것.
		if (!isBalanced(z)) break;
		else z = z->parent;
	}
	if (z == NULL) return;		//z가 NULL이면 불균형이 없으므로 종료한다.

	y = z->l;				// z의 높은 자식을 y에 저장
	if (y->h < z->r->h) y = z->r;

	x = y->l;				//  y의 높은 자식을 x에 저장	
	if (x->h < y->r->h) x = y->r;

	restructure(x, y, z, r);	// x, y, y restructure호출

	return;
}
int updateHeight(Node* w)
{

	if (isExternal(w)) {	//외부노드면 종료하고 높이는 1로 저장한다.
		w->h = 1;
		return;
	}
	else {
		updateHeight(w->l);
		updateHeight(w->r);		//순회하는 곳.
		int g;
		g = w->l->h;
		if (g < w->r->h)  //높은 자식의 높이를 g에 저장한다.
			g = w->r->h;
		w->h = g + 1;	//높이를 갱신한다.

		return;

	}
	return;
}
int isBalanced(Node* w)
{


	int height = w->l->h - w->r->h;

	if (height < 0)		//높이가 음수면 양수로 바꾼다,
		height = -height;

	if (height < 2) //높이가 2미만이면 균형이 맞으므로 1을 반환한다.
		return 1;

	return	0; //불균형이므로 0을 반환한다.
}
Node* restructure(Node* x, Node* y, Node* z, Node** r)
{
	Node* a, * b, * c;
	Node* T[4];

	if (z->r == y) {  //z의 오른쪽 자식이 y이면
		a = z;
		b = y;
		c = x;
		T[0] = z->l;
		T[1] = y->l;
		T[2] = x->l;
		T[3] = x->r;
		//단일 회전 일경우 216~222
		if (x == y->l) {//y의 왼쪽자식이 x이면 이중회전일경우이다
			b = x;
			c = y;
			T[0] = z->l;
			T[1] = x->l;
			T[2] = x->r;
			T[3] = y->r;
		}
	}
	else { //z의 왼쪽자식이 y이면

		a = y;
		b = x;
		c = z;
		T[0] = y->l;
		T[1] = x->l;
		T[2] = x->r;
		T[3] = z->r;
		//단일 회전 일경우 235~241
		if (y->l == x) { //y의 왼쪽자식이 x이면 이중회전일경우이다.
			a = x;
			b = y;
			T[0] = x->l;
			T[1] = x->r;
			T[2] = y->r;
			T[3] = z->r;
		}
	}
	if (z->parent == NULL) { //z가 NULL이면 root는 b로저장한다.
		(*r) = b;
		a->r = NULL;
		b->parent = NULL;
		b->l = NULL;
		b->r = NULL;
	}
	else if (z->parent->l == z) { //z가 왼쪽 자식일경우 
		b->parent = z->parent;
		b->l = NULL;
		b->r = NULL;
		z->parent->l = b;
		z->parent = NULL;
	}
	else {
		z->parent->r = b;
		b->parent = z->parent;
	}

	a->l = T[0];
	T[0]->parent = a;
	a->r = T[1];
	T[1]->parent = a;
	//  T_0 과 T_1 을 각각 a의 왼쪽 및 오른쪽 부트리로 만든다.
	c->l = T[2];
	T[2]->parent = c;
	c->r = T[3];
	T[3]->parent = c;
	//T_2와 T_3를 각각 c의 왼쪽 및 오른쪽 부트리로 만든다.
	b->r = c;
	c->parent = b;
	b->l = a;
	a->parent = b;
	// a와 c를 각각  b의 왼쪽 및 오른쪽 자식으로 만든다.
	return b;
}
void searchAndFixAfterRemoval(Node* w, Node** r) {
	Node* x, * y, * z;
	z = w;
	while (z != NULL) {		//루트까지 올라가면서 불균형 노드를 찾는 것.
		if (!isBalanced(z)) break;
		else z = z->parent;
	}
	if (z == NULL) return; //불균형이 없으므로 함수 종료.

	y = z->l;				// z의 높은 자식을 y에 저장한다.
	if (y->h < z->r->h) y = z->r;

	x = y->l;				//  y의 높은 자식을 x	에 저장한다.		
	if (x->h < y->r->h) x = y->r;

	
	Node *b=restructure(x, y, z, r);	// x, y, y restructure
	if (b == *r)return;		//b가 root이면 종료한다.
	updateHeight(b->parent);//높이를 갱신한다.
	return;
}

int removeElement(Node** v, int k) {

	Node* w = treeSearch(*v, k); //k값을 가진 노드를 찾는다
	Node* zs = NULL;
	if (isExternal(w)) //외부노드면 k값을가진 노드가 없기때문에 종료한다.
		return 0;
	int key = w->key;
	Node* z = w->l;
	if (!isExternal(z))  //외부노드가 아니면 z에 w오른쪽 자식을 저장한다.
		z = w->r;
	if (isExternal(z)) //외부노드면 
		zs = reduceExternal(&z); //w와 z를 삭제한다.

	else {
		Node* y = inOrderSucc(w);	//중위 후계자를 찾는다.
		Node* z = y->l;
		w->key = y->key;
		zs = reduceExternal(&z);//노드 y와 z를 삭제한다.
	}
	updateHeight(*v); 

	searchAndFixAfterRemoval(zs->parent, v); //균형을 복구한다.
	return key;
}
