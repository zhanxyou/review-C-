#include "Header.h"

void INIT_GAME_COM(void** player, char* name) {
	struct Player* player1 = malloc(sizeof(struct Player));
	if (player1 == NULL) {
		printf("inital fail\n");
		return;
	}

	strcpy(player1->name, name);
	player1->level = 0;
	player1->exp = 0;

	*player = player1;
}

//combat  //1:win 0:fail  //player, difficulty
int FIGHT_GAME_COM(void* p, int difficulty) {
	struct Player* player = p;
	int addExp = 0; //add exp

	switch (difficulty)
	{
	case 1:
		addExp = isWin(90, 1);
		break;
	case 2:
		addExp = isWin(50, 2);
		break;
	case 3:
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}

	player->exp += addExp;
	player->level = player->exp / 10;

	if (addExp == 0) {
		return 0;
	}
	else {

		return 1;
	}
}

int isWin(int winRate, int diff) {
	int random = rand() % 100 + 1; //1--100
	if (random <= winRate) {
		return diff * 10;
	}
	else {
		return 0;
	}
}
//player info
void PRINT_GAME_COM(void* p) {
	struct Player* player = p;
	printf("player:%s\nplayer lvl:%d\nplayer exp:%d\n", player->name, player->level, player->exp);


}

//exit game
void EXIT_GAME_COM(void* player) {
	if (player == NULL) {
		return;
	}

	free(player);
	player = NULL;

}