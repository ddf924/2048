#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;
#ifndef R_H
#define R_H

class Produce
{	
public:
	int board[4][4];
	Produce();//��l�ƹC�����O
	void setBoard();
	void generate_random_tile();//�H�����ͤ��
	void print_board();//�L�X��l�e���B��s��e��
};

#endif

