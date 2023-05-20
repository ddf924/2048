#ifndef GAME_H
#define GAME_H
#include<iostream>
using namespace std;

class Game
{
private:
	int board[4][4];
	void shiftLeft();
	void mergeLeft();
	void moveLeft();
	void shiftRight();
	void mergeRight();
	void moveRight();
	void shiftUp();
	void mergeUp();
	void moveUp();
	void shiftDown();
	void mergeDown();
	void moveDown();
	bool isGameOver();
public:
	Game();
	void play();
};	
#endif
