#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "Header.h"


#if 0
int isLeft(char ch) {
	return ch == '(';
}

int isRight(char ch) {
	return ch == ')';
}

void printError(char* str, char* errMsg, char * p) {
	printf("error,%s\n", errMsg);
	printf("%s\n", str);
	int num = p - str;

	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("!");
	
}

void test01() {
	char* str = "5+5*(6)+9/3*1)-(1+3(";
	//char* str = "5+5*(6)+9/3*1-(1+3(";

	char* p = str;

	SeqStack myStack = init_SeqStack();

	while (*p != '\0') {
		// "(" --> stack
		if (isLeft(*p)) {
			push_SeqStack(myStack,p);
		}

		if (isRight(*p)) {
			//if stack not empyty
			if (size_SeqStack(myStack) > 0) {
				pop_SeqStack(myStack);
			}
			else {
				printError(str, "not matching", p);
				break;
			}
		}
		p++;
	}

	while (size_SeqStack(myStack) > 0) {
		printError(str, "not matching to ')'", top_SeqStack(myStack));
		pop_SeqStack(myStack);
	}

	destroy_SeqStack(myStack);



}


int main(void)
{
	test01(); 
	return 0;
}

#endif