#pragma once
#define _CRT_SECURE_NO_WARNINGS //or #pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DynamicArray {
	void** pAddr;
	int m_capacity;
	int m_size;
};
struct DynamicArray* init_DynamicArray(int capacity);

void insert_dynamicArray(struct DynamicArray* array, int pos, void* data);

void foreach_DynamicArray(struct DynamicArray* array, void(*myPrint)(void*));

void removeByPos_DynamicArray(struct DynamicArray* array, int pos);

void removeByValue_DynamicArray(struct DynamicArray* array, void* data, int(*myCompare)(void*, void*));

void destory_DynamicArray(struct DynamicArray* array);

