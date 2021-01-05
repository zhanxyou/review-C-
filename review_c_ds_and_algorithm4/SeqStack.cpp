#include "Header.h"
#include "Header1.h"

#if 1
#define MAX 1024

struct SStack {
	void* data[MAX];
	int m_Size;
};

typedef void* SeqStack;

SeqStack init_SeqStack() {
	struct SStack * myStack = malloc(sizeof(struct SStack));
	if (myStack == NULL) {
		return NULL;
	}

	memset(myStack->data, 0, sizeof(void*) * MAX);

	myStack->m_Size = 0;

	return myStack;
}

void push_SeqStack(SeqStack stack, void* data) {
	if (stack == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	struct SStack* mystack = stack;
	if (mystack->m_Size == MAX) {
		return;
	}

	mystack->data[mystack->m_Size] = data;

	mystack->m_Size++;
}

void pop_SeqStack(SeqStack stack) {
	if (stack == NULL) {
		return;
	}
	struct SStack* mystack = stack;

	if (mystack->m_Size == 0) { return; }

	mystack->data[mystack->m_Size - 1] = NULL;

	mystack->m_Size--;
}

void* top_SeqStack(SeqStack stack) {
	if (stack == NULL) {
		return NULL;
	}
	struct SStack* mystack = stack;

	if (mystack->m_Size == 0) { return NULL; }

	return mystack->data[mystack->m_Size - 1];
}

int size_SeqStack(SeqStack stack) {
	if (stack == NULL) { return -1; }
	struct SStack* mystack = stack;

	return mystack->m_Size;
}

int isEmpty_SeqStack(SeqStack stack) {
	if (stack == NULL) { return -1; }

	struct SStack* mystack = stack;

	if (mystack->m_Size == 0) { return 1; }

	return 0;
}

void destroy_SeqStack(SeqStack stack) {
	if (stack == NULL) { return; }

	free(stack);
	stack = NULL;

}

#if 0 
struct Person {
	char name[64];
	int age;
};

int main()
{
	SeqStack myStack = init_SeqStack();
	struct Person p1 = {"aaa",10 };
	struct Person p2 = {"bbb",20 };
	struct Person p3 = {"ccc",30 };
	struct Person p4 = {"ddd",40 };
	struct Person p5 = {"eee",50 };

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
#endif 