#include "Header.h"


sstack init(){
	struct Stack* stack = malloc(sizeof(struct Stack));

	stack->data = malloc(sizeof(void*) * MAX);
	//memset(stack->data, 0, sizeof(void*) * MAX);  for void*data[MAX] type
	stack->m_size = 0;
	return stack;
}
void pushStack(sstack s, void* data) {
	if (s == NULL)
		return;
	if (data == NULL)
		return;

	struct Stack* stack = s;
	if (stack->m_size == MAX) {
		return;
	}
	stack->data[stack->m_size] = data;

	stack->m_size++;

}

void printStack(sstack s, void(*myprint)(void*)) {
	if (s == NULL)
		return;

	struct Stack* stack = s;

	for (int i = 0; i < stack->m_size; i++)
	{
		myprint(stack->data[i]);
	}

}

void popStack(sstack s) {
	if (s == NULL)
		return;
	
	struct Stack* stack = s;
	if (stack->m_size != 0) {
		stack->data[stack->m_size - 1] = NULL;
		stack->m_size--;
	}
	
	return;
}

sstack* topStack(sstack s) {
	if (s == NULL)
		return NULL;

	struct Stack* stack = s;
	if (stack->m_size != 0) {
		return stack->data[stack->m_size - 1];
	}

	return NULL;
}
int isEmptyStack(sstack s) {
	if (s == NULL)
		return -1;

	struct Stack* stack = s;
	if (stack->m_size == 0) {
		return 1;
	}

	return 0;
}
int sizeStack(sstack s) {
	if (s == NULL)
		return -1;

	struct Stack* stack = s;
	if (stack->m_size != 0) {
		return stack->m_size;
	}

	return 0;
}

void clearStack(sstack s) {
	if (s == NULL)
		return;

	struct Stack* stack = s;
	
	if (stack->data != NULL) {
		free(stack->data);
		stack->data = NULL;
	}

}

void destroyStack(sstack s) {
	if (s == NULL)
		return;

	clearStack(s);

	free(s);
	s = NULL;

}

#if 0
struct Person {
	char name[64];
	int age;
};

int main()
{
	sstack myStack = init();
	struct Person p1 = { "aaa",10 };
	struct Person p2 = { "bbb",20 };
	struct Person p3 = { "ccc",30 };
	struct Person p4 = { "ddd",40 };
	struct Person p5 = { "eee",50 };

	pushStack(myStack, &p1);
	pushStack(myStack, &p2);
	pushStack(myStack, &p3);
	pushStack(myStack, &p4);
	pushStack(myStack, &p5);

	while (isEmptyStack(myStack)==0) {
		struct Person* p = topStack(myStack);
		printf("%s : %d\n", p->name, p->age);
		popStack(myStack);
	}

	printf("size: %d\n", sizeStack(myStack));

	return 0;
}
#endif