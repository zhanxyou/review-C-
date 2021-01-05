#include "Header.h"

#if 0
struct LinkNode {
	void* data;
	struct LinkNode* next;

};

struct LList {
	struct LinkNode pHeader;
	int m_size;
};

typedef void* LinkList;

//initialize
LinkList init_LinkList() {
	struct LList* myList = malloc(sizeof(struct LList));

	if (myList == NULL)
		return NULL;

	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->m_size = 0;

	return myList;
}
void insert_LinkList(LinkList list, int pos, void* data) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}

	struct LList* myList = list;

	if ((pos < 0) || (pos > myList->m_size)) {
		pos = myList->m_size;
	}
	//find position
	struct LinkNode*pCurrent = &myList->pHeader; //***important "&"

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//new node
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data= data;
	newNode->next = NULL;
	//connect
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	myList->m_size++;
}

void foreach_LinkList(LinkList list,void(*myForeach)(void*)) {
	if (list == NULL) {
		return;
	}
	struct LList* myList = list;

	struct LinkNode* pCurrent = myList->pHeader.next;

	for (int i = 0; i < myList->m_size; i++)
	{
		myForeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}

void removeByPos_LinkList(LinkList list, int pos) {
	if (list == NULL) {
		return;
	}

	struct LList* myList = list;
	
	if (pos < 0 || pos > myList->m_size - 1) {
		return;
	}

	struct LinkNode* pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	free(pDel);
	pDel;

	myList->m_size--;
}
void removeByValue_LinkList(LinkList list, void* data, int(*myCmp)(void*, void*)) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	struct LList* myList = list;

	struct LinkNode* pPrev = &myList->pHeader;
	struct LinkNode* pCurrent = pPrev->next;

	for (int i = 0; i < myList->m_size; i++)
	{
		if (myCmp(pCurrent->data, data)) {
			pPrev->next = pCurrent->next;
			free(pCurrent);
			pCurrent = NULL;

			myList->m_size--;
			break;
		}

		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

void clear_LinkList(LinkList list) {
	if (list == NULL) {
		return;
	}
	struct LList* mylist = list;

	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	mylist->pHeader.next = NULL;
	mylist->m_size = 0;
}

int size_LinkLIst(LinkList list) {
	if (list == NULL) {
		return -1;
	}

	struct LList* mylist = list;

	return mylist->m_size;

}


void destory_LinkList(LinkList list) {
	if (list == NULL) {
		return;
	}

	clear_LinkList(list);

	free(list);

	list = NULL;

}

//client test
struct Person {
		char name[64];
		int age;
};
void myPrintPerson(void* data) {
	struct Person* p = data;
	printf("%s : %d\n", p->name, p->age);
}
int myCmp(void* data1, void* data2) {
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test01() {
	struct Person p1 = { "1",1 };
	struct Person p2 = { "2",2 };
	struct Person p3 = { "3",3 };
	struct Person p4 = { "4",4 };
	struct Person p5 = { "5",5 };
	struct Person p6 = { "6",6 };

	LinkList mylist = init_LinkList();

	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist,-1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 0, &p6);

	foreach_LinkList(mylist, myPrintPerson);
	printf("length: %d\n", size_LinkLIst(mylist));


	removeByPos_LinkList(mylist, 4);
	printf("----------------------\n");
	foreach_LinkList(mylist, myPrintPerson);
	printf("length: %d\n", size_LinkLIst(mylist));

	printf("----------------------\n");

	struct Person p = { "2",2 };
	removeByValue_LinkList(mylist, &p, myCmp);
	foreach_LinkList(mylist, myPrintPerson);
	printf("length: %d\n", size_LinkLIst(mylist));

	//clear linklist
	clear_LinkList(mylist);
	printf("----------------------\n");
	printf("length: %d\n", size_LinkLIst(mylist));

	destory_LinkList(mylist);
	mylist = NULL;

}

int main(void)
{
	test01();

	return 0;
}
#endif