#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#if 1
#define MAX 1024
struct Stack {
	void** data;
	int m_size;
};

typedef void* sstack;

sstack init();

void pushStack(sstack s, void* data);

void printStack(sstack s, void(*myprint)(void*));

void popStack(sstack s);

sstack* topStack(sstack s);

int isEmptyStack(sstack s);

int sizeStack(sstack s);

void clearStack(sstack s);

void destroyStack(sstack s);
#endif 