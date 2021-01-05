#define _CRT_SECURE_NO_WARNINGS //or #pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
#include <time.h>
//initialization		//player pointer,player name
typedef void(*INIT_GAME)(void** player, char* name); //函数指针
//combat  //1:win 0:fail    //player, difficulty
typedef int(*FIGHT_GAME)(void* player, int difficulty);
//player info
typedef void(*PRINT_GAME)(void* player);
//exit game
typedef void(*EXIT_GAME)(void* player);

void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame) {
	//initializing
	void* player = NULL;
	printf("input name:");
	char userName[64];
	scanf("%s", userName);
	init(&player, userName);
	
	int diff = -1;
	while (1) {
		getchar();
		system("cls");
		printf("difficulty level:\n");
		printf("1. Easy\n");
		printf("2. Middion\n");
		printf("3. Hard\n");

		scanf("%d", &diff);
		getchar(); //取走换行符

		int ret = fight(player, diff);
		if (ret == 0) {
			printf("you lose\n");
			break;
		}
		else {
			printf("you win\n");
			printGame(player);
		}
	}
	//exit game
	exitGame(player);
}

#if 0
int main(void)
{
	srand((unsigned int)time(NULL));
	playGame(INIT_GAME_COM, FIGHT_GAME_COM, PRINT_GAME_COM, EXIT_GAME_COM);
	return 0;
}
#endif
