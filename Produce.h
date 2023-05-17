#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;
#ifndef R_H
#define R_H

class Produce
{
private:
	int board[4][4];
public:
	Produce();//初始化遊戲面板
	void setBoard();
	void generate_random_tile();//隨機產生方塊
	void print_board();//印出初始畫面、更新後畫面
};

#endif

