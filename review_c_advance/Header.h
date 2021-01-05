
#pragma once
#define _CRT_SECURE_NO_WARNINGS //or #pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Player {
	char name[64];
	int level; //player's level
	int exp; //player's exp
};

//接口
//initialization  //player pointer,player name
void INIT_GAME_COM(void** player, char* name); //函数指针

//combat  //1:win 0:fail  //player, difficulty
int FIGHT_GAME_COM(void* player, int difficulty);

//player info
void PRINT_GAME_COM(void* player);

//exit game
void EXIT_GAME_COM(void* player);

//if won or lose
int isWin(int winRate, int diff);