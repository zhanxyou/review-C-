#include "Header.h"

#if 0
#define MAX 1024

struct Queue{
	void* data[MAX];
	int qSize;
};

typedef void* QList;

QList init() {
	struct Queue* q = malloc(sizeof(struct Queue));

	if (q == NULL) { return NULL; }
	//memset只是初始化                      //除非开辟空间，否则不用释放
	memset(q->data, 0, sizeof(void*)*MAX); // q->data = malloc(sizeof(void*)*MAX); 
	q->qSize = 0;						   // free

	return q;
}

void push_queueList(QList ql, void* data) {
	if (ql == NULL) {
		return;
	}
	if (data == NULL) { 
		return;
	}

	struct Queue* myql = ql;
	if (myql->qSize == MAX) { return; }

	myql->data[myql->qSize] = data;

	myql->qSize++;
}

void printQueue(QList ql, void(*myprint)(void*)) {
	if (ql == NULL) {
		return;
	}
	struct Queue* myql = ql;
	for (int i = 0; i < myql->qSize; i++)
	{
		myprint(myql->data[i]);
	}
}

void pop_queueList(QList ql) {
	if (ql == NULL) {
		return;
	}

	struct Queue* myql = ql;
	if (myql->qSize == 0) {
		return;
	}

	for (int i = 0; i < myql->qSize; i++)
	{
		myql->data[i] = myql->data[i + 1];
	}

	myql->qSize--;
}
int size_queueList(QList ql) {
	if (ql == NULL) {
		return -1;
	}
	struct Queue* myql = ql;
	if (myql->qSize == 0) {
		return 0;
	}
	
	return myql->qSize;

}

int isEmpty(QList ql) {
	if (ql == NULL) {
		return -1;
	}
	struct Queue* myql = ql;
	if (myql->qSize == 0) {
		return 1;
	}
	return 0;
}

QList* top_elem(QList ql) {
	if (ql == NULL) {
		return NULL;
	}

	struct Queue* myql = ql;
	if (myql->qSize == 0) {
		return NULL;
	}

	return myql->data[0];
}

QList* bottom_elem(QList ql) {
	if (ql == NULL) {
		return NULL;
	}

	struct Queue* myql = ql;
	if (myql->qSize == 0) {
		return NULL;
	}

	return myql->data[myql->qSize-1];
}

void destroy_queueList(QList ql) {
	if (ql == NULL) {
		return;
	}
	free(ql); 
	ql = NULL;
}
struct Person {
	char name[64];
	int age;
};
void myprint(void* data) {
	struct Person* p = data;
	printf("%s : %d\n", p->name, p->age);
}
int main()
{
	struct Queue* ql = init();
	struct Person p1 = { "aaa",10 };
	struct Person p2 = { "bbb",20 };
	struct Person p3 = { "ccc",30 };
	struct Person p4 = { "ddd",40 };
	struct Person p5 = { "eee",50 };

	push_queueList(ql, &p1);
	push_queueList(ql, &p2);
	push_queueList(ql, &p3);
	push_queueList(ql, &p4);
	push_queueList(ql, &p5);

	printQueue(ql,myprint);
	printf("------------------\n");

	printf("%d\n", size_queueList(ql));
	printf("------------------\n");

	pop_queueList(ql);
	printQueue(ql, myprint);
	printf("------------------\n");

	myprint(top_elem(ql));
	printf("------------------\n");

	myprint(bottom_elem(ql));
	printf("------------------\n");

	destroy_queueList(ql);

	return 0;
}

#endif