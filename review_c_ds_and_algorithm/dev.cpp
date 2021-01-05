#include "Header.h"

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

	if (pos < 0 || pos > array->m_size - 1) {
		pos = array->m_size;
	}

	if (array->m_size == array->m_capacity) {
		//if capacity is full, get a bigger capacity
		int newCapacity = array->m_capacity * 2;
		void** newSpace = malloc(sizeof(void*) * newCapacity);

		memcpy(newSpace, array->pAddr, sizeof(void*) * array->m_capacity);

		free(array->pAddr);

		array->pAddr = newSpace;

		array->m_capacity = newCapacity;
	}

	//move element
	for (int i = array->m_size - 1; i >= pos; i--)
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
	if (NULL == array) { return; }

	if (pos < 0 || pos > array->m_size - 1) { return; }

	for (int i = pos; i < array->m_size - 1; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->m_size--;
}

void removeByValue_DynamicArray(struct DynamicArray* array, void* data, int(*myCompare)(void*, void*)) {
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
