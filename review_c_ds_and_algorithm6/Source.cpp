#include "Header1.h"
#include "Header.h"

/*
性质1: 在二叉树的第i层上至多有 2^(i-1) 个结点（i>0）
性质2: 深度为k的二叉树至多有 2^k-1 个结点（k>0）
性质3: 对于任何一棵二叉树，若度为2的结点数有n2个，则叶子数（n0）必定为n2＋1 
	 （即n0=n2+1）度为2 数 + 1 = 叶子数
性质4: 具有n个结点的完全二叉树的深度必为log2n+1  
      (如 log2 (15)    点击 15  log  /  2  log = floor(3.98686) => 3+1 = 4
性质5: 对完全二叉树，若从上至下、从左至右编号，
	  则编号为i 的结点，其左孩子编号必为2i，其右孩子编号必为2i＋1；
	  其双亲的编号必为i/2（i＝1 时为根,除外）
5.6   满二叉树   深度为k的数 并且节点数量为 2^k - 1 
5.7   完全二叉树  除了最后一层，上面是一颗满二叉树，
	  在最后一层上只缺少右边的若干结点。
*/

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

void calculateLeafNum(struct BTNode* root, int* p) {
	if (root == NULL) {
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		(*p)++;
	}

	calculateLeafNum(root->lchild, p);
	calculateLeafNum(root->rchild, p);
}

int calculateHeight(struct BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	int lheight = calculateHeight(root->lchild);
	int rheight = calculateHeight(root->rchild);
	int height = lheight > rheight ? lheight + 1 : rheight + 1;
	
	return height;
}
struct BTnode* copyTree(struct BTNode* root) {
	if (root == NULL) {
		return NULL;
	}

	struct BTNode* lchild = copyTree(root->lchild);
	struct BTNode* rchild = copyTree(root->rchild);

	struct BTNode* newNode = malloc(sizeof(struct BTNode));
	newNode->ch = root->ch;

	newNode->lchild = lchild;
	newNode->rchild = rchild;

	return newNode;

}

void freeTree(struct BTNode*root) {
	if (root == NULL) {
		return;
	}

	freeTree(root->lchild);
	freeTree(root->rchild);
	printf("%c\n", root->ch);
	free(root);
}
#endif

/*
将根节点 入栈
只要栈中元素个数大于 0  执行循环
获取栈顶元素
出栈
如果标志位真  直接输出  并且执行下一次循环
如果为假 将标志改为真
将右子树  左子树 根 入栈
执行下一次循环
*/

#if 0
struct BTNode {
	char ch;
	struct BTNode* lchild;
	struct BTNode* rchild;
	int flag;
};

void nonrecursion(struct BTNode* root) {

	SeqStack stack = init_SeqStack();

	push_SeqStack(stack, root); //将根节点 入栈

	while (size_SeqStack(stack)>0) {//只要栈中元素个数大于 0  执行循环
		
		struct BTNode* p = top_SeqStack(stack);//获取栈顶元素
		pop_SeqStack(stack); //**出栈

		if (p->flag == 1) {//如果标志位真  直接输出  并且执行下一次循环
			printf("%c ", p->ch);
			continue;
		}

		p->flag = 1;//如果为假 将标志改为真

		if (p->rchild != NULL) {//将右子树  左子树 根 入栈
			push_SeqStack(stack, p->rchild); 

		}
		if (p->lchild != NULL) {
			push_SeqStack(stack, p->lchild);
		}
												//  ^												//  |
		push_SeqStack(stack, p);				//  |
												//  |  
	}                                           // root left right

	destroy_SeqStack(stack);

}
#endif 

#if 0
void test01() {
	struct BTNode A = { 'A', NULL, NULL};
	struct BTNode B = { 'B', NULL, NULL};
	struct BTNode C = { 'C', NULL, NULL};
	struct BTNode D = { 'D', NULL, NULL};

	struct BTNode E = { 'E', NULL, NULL};
	struct BTNode F = { 'F', NULL, NULL};
	struct BTNode G = { 'G', NULL, NULL};
	struct BTNode H = { 'H', NULL, NULL};


	/*struct BTNode A = { 'A', NULL, NULL,0 };
	struct BTNode B = { 'B', NULL, NULL,0 };
	struct BTNode C = { 'C', NULL, NULL,0 };
	struct BTNode D = { 'D', NULL, NULL,0 };

	struct BTNode E = { 'E', NULL, NULL,0 };
	struct BTNode F = { 'F', NULL, NULL,0 };
	struct BTNode G = { 'G', NULL, NULL,0 };
	struct BTNode H = { 'H', NULL, NULL,0 };*/
	A.lchild = &B;
	A.rchild = &F;

	B.rchild = &C;

	C.lchild = &D;
	C.rchild = &E;

	F.rchild = &G;
	G.lchild = &H;

	//recursion(&A);
	//nonrecursion(&A);

	//calculate leaves
	int num = 0;
	calculateLeafNum(&A,&num);
	printf("leaves: %d\n", num);

	int height = calculateHeight(&A);
	printf("height: %d\n", height);

	//copy
	struct BTNode* newTree = copyTree(&A);
	recursion(newTree);

	freeTree(newTree);
}

#endif
#if 0
int main(void)
{
	test01();
	return 0;
}
#endif