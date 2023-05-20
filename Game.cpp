#include "Game.h"
#include<iostream>
using namespace std;

Game::Game() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			board[i][j] = 0;
		}
	}
}
void Game::play() {
	while (!isGameOver()) {
		generate_random_tile();
		generate_random_tile();
		print_board();

		char move;
		cin >> move;
		switch (move)
		{
		case 'w':
			moveUp();
			break;
		case 'a':
			moveLeft();
			break;
		case 's':
			moveDown();
			break;
		case 'd':
			moveRight();
			break;
		}
	}
}
void Game::print_board() {
	cout << "\n2048\n";
	cout << "-----------------------------\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "| " << board[i][j] << " ";
		}
		cout << "|\n";
		cout << "-----------------------------\n";
	}
}
void Game::generate_random_tile() {
	//srand(time(0)); // 設定亂數種子
	int val = (rand() % 2 + 1); // 隨機產生2或4
	int row, col;
	do {
		row = rand() % 4;
		col = rand() % 4;
	} while (board[row][col] != 0); // 找到一個空格子
	board[row][col] = val;
}

void Game::shiftLeft() {
	for (int i = 0;i < 4;i++) {
		int k = 0;
		for (int j = 0;j < 4;j++) {
			if (board[i][j] != 0) {
				board[i][k++] = board[i][j]; //非0方塊向左移
			}
		}
		while (k < 4) {
			board[i][k++] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
				board[i][j] *= 2;//方塊合併
				board[i][j + 1] = 0;
			}
		}
	}
}
void Game::moveLeft() {
	shiftLeft();
	mergeLeft();
	shiftLeft();
}
void Game::shiftRight() {
	for (int i = 0;i < 4;i++) {
		int k = 3;
		for (int j = 3; j >= 0; j--) {
			if (board[i][j] != 0) {
				board[i][k--] = board[i][j]; //非0方塊向右移
			}
		}
		while (k >= 0) {
			board[i][k--] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
				board[i][j] *= 2;//方塊合併
				board[i][j - 1] = 0;
			}
		}
	}
}
void Game::moveRight() {
	shiftRight();
	mergeRight();
	shiftRight();
}
void Game::shiftUp() {
	for (int j = 0;j < 4;j++) {
		int k = 0;
		for (int i = 0;i < 4;i++) {
			if (board[i][j] != 0) {
				board[k++][j] = board[i][j]; //非0方塊向上移
			}
		}
		while (k < 4) {
			board[k++][j] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (board[i][j] != 0 && board[i][j] == board[i + 1][j]) {
				board[i][j] *= 2;//方塊合併
				board[i + 1][j] = 0;
			}
		}
	}
}
void Game::moveUp() {
	shiftUp();
	mergeUp();
	shiftUp();
}
void Game::shiftDown() {
	for (int j = 0;j < 4;j++) {
		int k = 3;
		for (int i = 3;i >= 0;i--) {
			if (board[i][j] != 0) {
				board[k--][j] = board[i][j]; //非0方塊向下移
			}
		}
		while (k >= 0) {
			board[k--][j] = 0;//剩餘方塊補0
		}
	}
}
void Game::mergeDown() {
	for (int j = 0; j < 4; j++) {
		for (int i = 3; i > 0; i--) {
			if (board[i][j] != 0 && board[i][j] == board[i - 1][j]) {
				board[i][j] *= 2; // 相同方塊合併
				board[i - 1][j] = 0;
			}
		}
	}
}
void Game::moveDown() {
	shiftDown();
	mergeDown();
	shiftDown();
}
bool Game::isGameOver() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				return false; // 還有空格子，遊戲未結束
			}
			if (i > 0 && board[i][j] == board[i - 1][j]) {
				return false; // 還有相鄰且相同的方塊，遊戲未結束
			}
			if (j > 0 && board[i][j] == board[i][j - 1]) {
				return false; // 還有相鄰且相同的方塊，遊戲未結束
			}
		}
	}
	return true; // 沒有空格子且沒有相鄰且相同的方塊，遊戲結束
}
