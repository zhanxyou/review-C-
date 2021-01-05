#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#if 0
/*
 void* b;
 int * a;
 b = (int*)a; // b = a; 

 a = b; Error!!
 a = (int*)b; Correct!!
*/
struct StackNode {
	struct StackNode* next;
};
struct LStack {

	struct StackNode pHeader;
	int m_Size;
};

typedef void* LinkStack;

LinkStack init_SeqStack() {
	struct LStack* myStack = malloc(sizeof(struct LStack));
	if (myStack == NULL) {
		return NULL;
	}

	//memset(myStack->data, 0, sizeof(void*) * MAX);
	myStack->pHeader.next = NULL;
	myStack->m_Size = 0;

	return myStack;
}

void push_SeqStack(LinkStack stack, void* data) {
	if (stack == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	struct LStack* mystack = stack;

	struct StackNode* newNode = data;
	newNode->next = NULL;

	struct StackNode* pCurrent = mystack->pHeader.next;
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	mystack->m_Size++;

}

void pop_SeqStack(LinkStack stack) {
	if (stack == NULL) {
		return;
	}
	struct LStack* mystack = stack;
	struct StackNode* pCurrent = mystack->pHeader.next;

	if (mystack->m_Size == 0) { return; }

	
	mystack->pHeader.next = pCurrent->next;
	pCurrent = NULL;

	mystack->m_Size--;
}

void* top_SeqStack(LinkStack stack) {
	if (stack == NULL) {
		return NULL;
	}
	struct LStack* mystack = stack;

	if (mystack->m_Size == 0) { return NULL; }

	return mystack->pHeader.next;
}

int size_SeqStack(LinkStack stack) {
	if (stack == NULL) { return -1; }
	struct LStack* mystack = stack;

	return mystack->m_Size;
}

int isEmpty_SeqStack(LinkStack stack) {
	if (stack == NULL) { return -1; }

	struct LStack* mystack = stack;

	if (mystack->m_Size == 0) { return 1; }

	return 0;
}

void destory_SeqStack(LinkStack stack) {
	if (stack == NULL) { return; }

	free(stack);
	stack = NULL;
}

struct Person {
	struct StackNode node;
	char name[64];
	int age;
};

int main01()
{
	LinkStack myStack = init_SeqStack();
	struct Person p1 = { NULL,"aaa",10 };
	struct Person p2 = { NULL,"bbb",20 };
	struct Person p3 = { NULL,"ccc",30 };
	struct Person p4 = { NULL,"ddd",40 };
	struct Person p5 = { NULL,"eee",50 };

	push_SeqStack(myStack, &p1);
	push_SeqStack(myStack, &p2);
	push_SeqStack(myStack, &p3);
	push_SeqStack(myStack, &p4);
	push_SeqStack(myStack, &p5);

	while (isEmpty_SeqStack(myStack) == 0) {
		struct Person* p = top_SeqStack(myStack);
		printf("%s : %d\n", p->name, p->age);
		pop_SeqStack(myStack);
	}

	printf("size: %d\n", size_SeqStack(myStack));

	return 0;
}
#endif