#include "Header.h"

#if 0
struct DynamicArray {
	void** pAddr;
	int m_capacity;
	int m_size;
};
struct DynamicArray* init_DynamicArray(int capacity) {
	if (capacity <= 0) {
		return NULL;
	}
	struct DynamicArray* array = malloc(sizeof(struct DynamicArray));
	if (array == NULL) {
		return NULL;
	}
	array->pAddr = malloc(sizeof(void*) * capacity);
	array->m_capacity = capacity;
	array->m_size = 0;

	return array;
}
void insert_dynamicArray(struct DynamicArray* array, int pos, void* data) {
	if (array == NULL) {
		return;
	}
	if (data == NULL) { return; }

	if (pos < 0 || pos > array->m_size-1) {
		pos = array->m_size;
	}
	
	if (array->m_size == array->m_capacity) {
		//if capacity is full, get a bigger capacity
		int newCapacity = array->m_capacity * 2;
		void** newSpace= malloc(sizeof(void*) * newCapacity);
		
		memcpy(newSpace, array->pAddr, sizeof(void*) * array->m_capacity);

		free(array->pAddr);

		array->pAddr = newSpace;

		array->m_capacity = newCapacity;
	}

	//move element
	for (int i = array->m_size-1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	array->pAddr[pos] = data;
	array->m_size++;
}

void foreach_DynamicArray(struct DynamicArray* array, void(*myPrint)(void*)) {
	if (array == NULL) { return; }
	if (myPrint == NULL) { return; }
	for (int i = 0; i < array->m_size; i++)
	{
		myPrint(array->pAddr[i]);
	}

}
void removeByPos_DynamicArray(struct DynamicArray* array, int pos) {
	if (NULL == array) {return;}

	if (pos < 0 || pos > array->m_size-1) { return; }

	for (int i = pos; i < array->m_size-1; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->m_size--;
}

void removeByValue_DynamicArray(struct DynamicArray* array, void* data, int(*myCompare)(void*,void*)){
	if (array == NULL) { return; }
	if (data == NULL) { return; }

	for (int i = 0; i < array->m_size; i++)
	{
		if (myCompare(array->pAddr[i], data)) {
			removeByPos_DynamicArray(array, i);
			break;
		}
	}
}

void destory_DynamicArray(struct DynamicArray* array) {
	if (array == NULL)
		return;

	if (array->pAddr != NULL) {
		free(array->pAddr);
		array->pAddr = NULL;
	}


	free(array);
	array = NULL;
}
#endif

#if 0
#if 1

//client test
struct Person {
	char name[64];
	int age;
};

void myPrintPerson(void* data) {
	struct Person* p = data;
	printf("%s:%d\n", p->name, p->age);
}


int myCompare(void* data1, void* data2) {
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

#endif //test code

int main(void)
{
	struct DynamicArray * array  = init_DynamicArray(5);

#if 1
	struct Person p1 = {"1",1};
	struct Person p2 = {"2",2};
	struct Person p3 = {"3",3};
	struct Person p4 = {"4",4};
	struct Person p5 = {"5",5};
	struct Person p6 = {"6",6};
	printf("before: capacity: %d | size: %d\n", array->m_capacity, array->m_size);

	insert_dynamicArray(array, 0, &p1); //1
	insert_dynamicArray(array, 0, &p2); //2 1
	insert_dynamicArray(array, 1, &p3); //2 3 1 
	insert_dynamicArray(array, 0, &p4); //4 2 3 1
	insert_dynamicArray(array,-1, &p5); //4 2 3 1 5
	insert_dynamicArray(array, 2, &p6); //4 2 6 3 1 5

	foreach_DynamicArray(array, myPrintPerson);

	printf("after: capacity: %d | size: %d\n", array->m_capacity, array->m_size);

#endif //insert

#if 1
	removeByPos_DynamicArray(array, 2);

	foreach_DynamicArray(array, myPrintPerson);

	printf("after: capacity: %d | size: %d\n", array->m_capacity, array->m_size);

#endif //remove by positon 

#if 1
	struct Person p = {"1",1};

	removeByValue_DynamicArray(array, &p, myCompare);

	foreach_DynamicArray(array, myPrintPerson);

	printf("after: capacity: %d | size: %d\n", array->m_capacity, array->m_size);

#endif //remove by value

#if 1
	destory_DynamicArray(array);
	array = NULL;
#endif // 1

	return 0;
}
#endif