#include "Header.h"
#if 0
struct BTNode {
	char ch;
	struct BTNode* lchild;
	struct BTNode* rchild;
};

void recursion(struct BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->ch);
	recursion(root->lchild);
	recursion(root->rchild);
}
#endif


#if 1
struct BTNode {
	char ch;
	struct BTNode* lchild;
	struct BTNode* rchild;
	int flag;
};

void nonrecursion(struct BTNode* root) {
	sstack stack = init();

	pushStack(stack, root);

	while (sizeStack(stack) > 0) {
		struct BTNode* p = topStack(stack);
		popStack(stack);

		if (p->flag == 1) {
			printf("%c ", p->ch);
			continue;
		}

		p->flag = 1;

		if (p->rchild != NULL) {
			pushStack(stack,p->rchild);
		}
		if (p->lchild != NULL) {
			pushStack(stack, p->lchild);
		}
		pushStack(stack, p);
	
	}

	destroyStack(stack);


}
#endif
void test01() {
	struct BTNode A = { 'A', NULL, NULL,0};
	struct BTNode B = { 'B', NULL, NULL,0};
	struct BTNode C = { 'C', NULL, NULL,0};
	struct BTNode D = { 'D', NULL, NULL,0};
	struct BTNode E = { 'E', NULL, NULL,0};
	struct BTNode F = { 'F', NULL, NULL,0};
	struct BTNode G = { 'G', NULL, NULL,0};
	struct BTNode H = { 'H', NULL, NULL,0};

	A.lchild = &B;
	A.rchild = &F;

	B.rchild = &C;

	C.lchild = &D;
	C.rchild = &E;

	F.rchild = &G;
	G.lchild = &H;

	//recursion(&A);
	nonrecursion(&A);
}
#if 0
int main(void)
{
	test01();
	return 0;
}
#endif