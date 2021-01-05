#pragma once
#define MAX 1024

struct SStack {
	void* data[MAX];
	int m_Size;
};

typedef void* SeqStack;

SeqStack init_SeqStack();

void push_SeqStack(SeqStack stack, void* data);

void pop_SeqStack(SeqStack stack);

void* top_SeqStack(SeqStack stack);

int size_SeqStack(SeqStack stack);

int isEmpty_SeqStack(SeqStack stack);

void destroy_SeqStack(SeqStack stack);