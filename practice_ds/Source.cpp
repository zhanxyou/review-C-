#include "Header.h"
#if 0
struct dynamicArr {
	void** arr;
	int capacity;
	int aSize;
};

typedef void* Array;

struct dynamicArr* init_dynamicArr(int capacity) {
	if (capacity <= 0) {
		return NULL;
	}

	struct dynamicArr* arr = malloc(sizeof(struct dynamicArr));
	if (NULL == arr) {
		return NULL;
	}

	arr->arr = malloc(sizeof(void*) * capacity);
	arr->capacity = capacity;
	arr->aSize = 0;

	return arr;
}

void insert_elem(Array arr, int pos, void* data) {
	if (NULL == arr) {
		return;
	}
	if (data == NULL) {
		return;
	}

	struct dynamicArr* myarr = arr;

	if (pos <0 || pos > myarr->aSize - 1) {
		pos = myarr->aSize;
	}

	if (myarr->aSize == myarr->capacity) {
		int newcapacity = myarr->capacity * 2;
		void** newarr = malloc(sizeof(void*) *newcapacity);

		memcpy(newarr, myarr->arr, sizeof(void*) * newcapacity); //**

		free(myarr->arr);
		myarr->arr = newarr;
		myarr->capacity = newcapacity;
	}

	for(int i = myarr->aSize-1; i >=pos; i--)  //**
	{
		myarr->arr[i + 1] = myarr->arr[i];
	}

	myarr->arr[pos] = data;

	myarr->aSize++;
}

void printArr(Array arr, void(*myprint)(void*)) {
	if (arr == NULL) { return; }

	struct dynamicArr* myarr = arr;

	if (myarr->aSize == 0) {
		return;
	}

	for (int i = 0; i < myarr->aSize; i++)
	{
		myprint(myarr->arr[i]);
	}
}

void removeByPos(Array arr, int pos) {
	if (arr == NULL) { return; }

	struct dynamicArr* myarr = arr;
	for (int i = pos; i <myarr->aSize-1; i++)
	{
		myarr->arr[i] = myarr->arr[i + 1];
	}

	myarr->aSize--;

}

void removeByValue(Array arr, void* data, int(*mycmp)(void*,void*)) {
	if (arr == NULL) {
		return;
	}
	struct dynamicArr* myarr = arr;
	for (int i = 0; i < myarr->aSize-1; i++)
	{
		if (mycmp(myarr->arr[i], data)) {
			removeByPos(myarr, i);
			break;
		}
	}
	
}

void destroy_arr(Array arr) {
	if (arr == NULL) { return; }
	
	struct dynamicArr* myarr = arr;
	if (myarr->arr != NULL) {
		free(myarr->arr);
		myarr->arr = NULL;
	}
	free(arr);
	arr = NULL;
}
struct Person {
	char name[64];
	int age;
};
void myprint(void* data) {
	struct Person* p = data;
	printf("%s : %d\n", p->name, p->age);
}
int mycmp(void* data1, void* data2) {
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}
int main(void)
{
	struct dynamicArr* myarr = init_dynamicArr(5);

	struct Person p1 = { "1",1 };
	struct Person p2 = { "2",2 };
	struct Person p3 = { "3",3 };
	struct Person p4 = { "4",4 };
	struct Person p5 = { "5",5 };
	struct Person p6 = { "6",6 };
	printf("before: capacity: %d | size: %d\n", myarr->capacity, myarr->aSize);

	insert_elem(myarr, 0, &p1); //1
	insert_elem(myarr, 0, &p2); //2 1
	insert_elem(myarr, 1, &p3); //2 3 1 
	insert_elem(myarr, 0, &p4); //4 2 3 1
	insert_elem(myarr, -1, &p5); //4 2 3 1 5
	insert_elem(myarr, 2, &p6); //4 2 6 3 1 5
	printf("after: capacity: %d | size: %d\n", myarr->capacity, myarr->aSize);

	printArr(myarr, myprint);
	printf("---------------------\n");

	removeByPos(myarr, 2);
	printArr(myarr, myprint);
	printf("---------------------\n");

	struct Person p = { "1",1 };
	removeByValue(myarr, &p, mycmp);
	printArr(myarr, myprint);
	printf("---------------------\n");

	destroy_arr(myarr);
	myarr = NULL;
	return 0;
}

#endif
