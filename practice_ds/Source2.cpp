#include "Header.h"

#if 0
struct LinkNode {
	struct LinkNode* next;
};
struct LList {
	struct LinkNode pHeader;
	int Size;
};
typedef void* LinkList;

struct LList* init_list() {
	struct LList* mylist = malloc(sizeof(struct LList));
	mylist->pHeader.next = NULL;
	mylist->Size = 0;

	return mylist;
}

void insert_list(LinkList list, int pos, void* data) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}

	struct LList* mylist = list;

	if (pos < 0 || pos > mylist->Size) {
		pos = mylist->Size;
	}

	struct LinkNode* newNode = data;
	newNode->next = NULL;

	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	mylist->Size++;
}

void print_list(LinkList list, void(*myprint)(void*)) {
	if (list == NULL) { return; }
	struct LList* mylist = list;

	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->Size; i++)
	{
		myprint(pCurrent);
		pCurrent = pCurrent->next;
	}

}

void removeByPos(LinkList list, int pos) {
	if (list == NULL) {
		return;
	}

	struct LList* mylist = list;
	struct LinkNode* pCurrent = &mylist->pHeader;
	//struct LinkNode* pPrev = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	struct LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	
	mylist->Size--;
}
void removeByValue(LinkList list, void* data, int(*mycmp)(void*, void*)) {
	if (NULL == list) { return; }

	struct LList* mylist = list;
	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->Size; i++)
	{
		//pCurrent = pCurrent->next;
		if (mycmp(pCurrent, data)) {
			removeByPos(mylist, i);
			break;
		}
		pCurrent = pCurrent->next;

	}


}
int size_list(LinkList list) {
	if (list == NULL) {
		return -1;
	}

	struct LList* mylist = list;

	if (mylist->Size == 0) {
		return 0;
	}

	return mylist->Size;

}

void clear_list(LinkList list) {
	if (list == NULL) {
		return;
	}
	struct LList* mylist = list;

	mylist->pHeader.next = NULL;
	mylist->Size = 0;
}

void destory_list(LinkList list) {
	if (list == NULL) {
		return;
	}
	clear_list(list);

	free(list);
	list = NULL;

}
struct Person {
	struct LinkNode node;
	char name[64];
	int age;
};

void myprint(void* data) {
	if (data == NULL) { return; }
	struct Person*p = data;
	printf("%s : %d\n", p->name, p->age);
}
int mycmp(void* data1, void* data2) {
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}
int main()
{
	struct LList* list = init_list();

	struct Person p1 = { NULL,"1",1 };
	struct Person p2 = { NULL,"2",2 };
	struct Person p3 = { NULL,"3",3 };
	struct Person p4 = { NULL,"4",4 };
	struct Person p5 = { NULL,"5",5 };
	struct Person p6 = { NULL,"6",6 };

	insert_list(list, 0, &p1);
	insert_list(list, 0, &p2);
	insert_list(list, 1, &p3);
	insert_list(list, 0, &p4);
	insert_list(list, -1, &p5);
	insert_list(list, 2, &p6);

	print_list(list, myprint);
	printf("-----------------------\n");
	removeByPos(list, 1);
	print_list(list, myprint);


	printf("-----------------------\n");
	struct Person p = {NULL,"4",4 };
	removeByValue(list, &p, mycmp);
	print_list(list, myprint);
	printf("-----------------------\n");

	clear_list(list);
	print_list(list, myprint);
	printf("-----------------------\n");

	destory_list(list);
	return 0;
}
#endif