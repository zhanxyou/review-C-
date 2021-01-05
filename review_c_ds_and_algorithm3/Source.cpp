#include "Header.h"

#if 0 
struct LinkNode {
	struct LinkNode* next;
};

struct LList {
	struct LinkNode pHeader;
	int m_size;
};

typedef void* LinkList;

LinkList init_LinkList() {
	struct LList* myList = malloc(sizeof(struct LList));

	if (myList == NULL) {
		return NULL;
	}

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
	if (pos < 0 || pos > myList->m_size - 1) {
	
		pos = myList->m_size;
	}

	struct LinkNode* myNode = data; //强转成前4个字节数据 **important

	struct LinkNode* pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	myList->m_size++;
}

void foreach_LinkList(LinkList list, void(*myForeach)(void*)) {

	if (list == NULL) {
		return;
	}

	struct LList* myList = list;

	struct LinkNode* myNode = myList->pHeader.next; 

	for (int i = 0; i < myList->m_size; i++)
	{
		myForeach(myNode);
		myNode = myNode->next;
	}


}
void removeByPos_LinkList(LinkList list, int pos) {
	if (list == NULL) {
		return;
	}
	struct LList* mylist = list;

	if (pos < 0 || pos > mylist->m_size - 1) {
		return;
	}

	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	//不用free，数据是用户管理释放
	mylist->m_size--;
}

void destory_LinkList(LinkList list) {
	if (list == NULL) {
		return;
	}
	free(list);
	list = NULL;
}


struct Person {
	struct LinkNode node; //void* node
	char name[64];
	int age;
};

void myPrintPerson(void* data) {
	struct Person* p = data;
	printf("%s : %d\n", p->name, p->age);
}

void test01() {
	LinkList mylist = init_LinkList();

	struct Person p1 = { NULL,"aaa",10 };
	struct Person p2 = { NULL,"bbb",20 };
	struct Person p3 = { NULL,"ccc",30 };
	struct Person p4 = { NULL,"ddd",40 };
	struct Person p5 = { NULL,"eee",50 };

	insert_LinkList(mylist,0,&p1);
	insert_LinkList(mylist,0,&p2);
	insert_LinkList(mylist,1,&p3);
	insert_LinkList(mylist,-1,&p4);
	insert_LinkList(mylist,0,&p5);

	foreach_LinkList(mylist, myPrintPerson);
	printf("----------------------------------\n");
	removeByPos_LinkList(mylist, 3);
	foreach_LinkList(mylist, myPrintPerson);

	destory_LinkList(mylist);
}

int main()
{
	test01();
	return 0;
}
#endif