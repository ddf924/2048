#ifndef GAME_H
#define GAME_H
#include<iostream>
#include"Produce.h"
using namespace std;

class Game
{
private:
	//int **board;
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
	Produce A;
	Game(Produce);
	void play();
};
#endif
