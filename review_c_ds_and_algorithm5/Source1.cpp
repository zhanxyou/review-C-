#include "Header.h"

#if 0
struct QNode{
	void* data;
	struct QNode* next;
};

struct QueueList {
	struct QNode pHeader;
	struct QNode* pTail;
	int qSize;
};

typedef void* QList;

QList init() {
	struct QueueList* q = malloc(sizeof(struct QueueList));

	if (q == NULL) { return NULL; }

	q->pHeader.next = NULL;
	q->pTail = &q->pHeader;
	q->pHeader.data = NULL;
	q->qSize = 0;		

	return q;
}

void push_queueList(QList ql, void* data) {
	if (ql == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}

	struct QueueList* myql = ql;

	struct QNode* newNode = malloc(sizeof(struct QNode));

	newNode->data = data;
	newNode->next = NULL;
	if (myql->qSize == 0) {
		myql->pHeader.next = newNode;
		myql->pTail = newNode;
	}
	else {
		myql->pTail->next = newNode;
		myql->pTail = newNode;
	}



	myql->qSize++;
}

void printQueue(QList ql, void(*myprint)(void*)) {
	if (ql == NULL) {
		return;
	}
	struct QueueList* myql = ql;
	struct QNode* pCurrent = myql->pHeader.next;

	while (pCurrent != NULL) { 
		myprint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void pop_queueList(QList ql) {
	if (ql == NULL) {
		return;
	}

	struct QueueList* myql = ql;
	struct QNode* pCurrent = myql->pHeader.next;
	if (myql->qSize == 0) {
		return;
	}

	myql->pHeader.next = pCurrent->next;
	pCurrent = NULL;

	myql->qSize--;
}
int size_queueList(QList ql) {
	if (ql == NULL) {
		return -1;
	}
	struct QueueList* myql = ql;
	if (myql->qSize == 0) {
		return 0;
	}

	return myql->qSize;

}

int isEmpty(QList ql) {
	if (ql == NULL) {
		return -1;
	}
	struct QueueList* myql = ql;
	if (myql->qSize == 0) {
		return 1;
	}
	return 0;
}

QList* top_elem(QList ql) {
	if (ql == NULL) {
		return NULL;
	}

	struct QueueList* myql = ql;
	if (myql->qSize == 0) {
		return NULL;
	}

	return myql->pHeader.next->data;
}

QList* bottom_elem(QList ql) {
	if (ql == NULL) {
		return NULL;
	}

	struct QueueList* myql = ql;
	if (myql->qSize == 0) {
		return NULL;
	}

	return myql->pTail->data;
}

void destroy_queueList(QList ql) {
	if (ql == NULL) {
		return;
	}
	struct QueueList* myql = ql;
	struct QNode* pCurrent = myql->pHeader.next;

	for (int i = 0; i < myql->qSize; i++)
	{
		struct QNode* pPrev = pCurrent->next; //**
		free(pCurrent);
		pCurrent = pPrev;

	}


	myql->pHeader.next = NULL;
	myql->qSize = 0;

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

	printQueue(ql, myprint);
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
