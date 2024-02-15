#include "algorithm.h"
#include <Windows.h>
char block = 32;
int minValue(int x, int y) {
	return x < y ? x : y;
}
int maxValue(int x, int y) {
	return x > y ? x : y;
}
void gotoxy(short x, short y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
bool X_Axis(char** board, int xA, int xB, int y, char ch) {
	int min = minValue(xA, xB);
	int max = maxValue(xA, xB);
	for (int i = min; i <= max; i++) {
		if (board[y][i] == block)
			continue;
		if (board[y][i] != ch)
			return false;
	}
	return true;
}
bool Y_Axis(char** board, int yA, int yB, int x, char ch) {
	int min = minValue(yA, yB);
	int max = maxValue(yA, yB);
	for (int i = min; i <= max; i++) {
		if (board[i][x] == block) continue;
		if (board[i][x] != ch)
			return false;
	}
	return true;
}
bool IMatching(char** board, point A, point B) {
	char ch = board[A.y][A.x];
	if (A.y == B.y)
		if (X_Axis(board, A.x, B.x, A.y, ch))
			return true;
	if (A.x == B.x)
		if (Y_Axis(board, A.y, B.y, A.x, ch))
			return true;
	return false;
}
bool ZMatching(char** board, point A, point B) {
	point min = A, max = B;
	if (A.x > B.x) {
		min = B;
		max = A;
	}
	char ch;
	ch = board[min.y][min.x];
	for (int x = min.x + 1; x < max.x; x++) {
		if (X_Axis(board, min.x, x, min.y, ch))
			if (Y_Axis(board, min.y, max.y, x, ch))
				if (X_Axis(board, x, max.x, max.y, ch))
					return true;
	}
	//Z vertical
	min = A, max = B;
	if (A.y > B.y) {
		max = A;
		min = B;
	}
	ch = board[min.y][min.x];

	for (int y = min.y + 1; y < max.y; y++) {
		if (Y_Axis(board, min.y, y, min.x, ch))
			if (X_Axis(board, min.x, max.x, y, ch))
				if (Y_Axis(board, y, max.y, max.x, ch))
					return true;
	}


	return false;
}
char** extendBoard(char** a) {
	char** board = new char* [6];
	for (int i = 0; i < 6; i++)
	{
		board[i] = new char[6];
	}
	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++)
			board[i][j] = a[i - 1][j - 1];
	for (int i = 0; i < 6; i++) {
		board[i][5] = block;
		board[5][i] = block;
		board[i][0] = block;
		board[0][i] = block;
	}
	return board;
}
bool U_L_horizontal(char** a, point A, point B) {
	point min = A, max = B;
	if (A.y > B.y) {
		min = B;
		max = A;
	}
	char** board = extendBoard(a);
	min.x++; min.y++;
	max.x++; max.y++;
	char ch = board[min.y][min.x];


	int i = 0;
	/*
	_________
			|
	________|


	*/
	if (min.x < max.x) {
		while (max.x + i < 6) {
			if (X_Axis(board, min.x, max.x, min.y, ch) && board[min.y][max.x + i] == block) {
				if (Y_Axis(board, min.y, max.y, max.x + i, ch)) {
					if (X_Axis(board, max.x, max.x + i, max.y, ch))
						return true;
				}
			}
			else return false;
			i++;
		}
	}
	else {
		while (min.x + i < 6) {
			if (X_Axis(board, max.x, min.x, max.y, ch) && board[max.y][min.x + i] == block) {
				if (Y_Axis(board, min.y, max.y, min.x + i, ch)) {
					if (X_Axis(board, min.x, min.x + i, min.y, ch))
						return true;
				}
			}
			else if (max.x != min.x)
				return false;
			i++;
		}
	}
	return false;
}
bool U_L_Vertical(char** a, point A, point B) {
	point min = A, max = B;
	if (A.x > B.x) {
		min = B;
		max = A;
	}
	char** board = extendBoard(a);
	min.x++; min.y++;
	max.x++; max.y++;
	char ch = board[min.y][min.x];
	int i = 0;
	/*
	|   |
	|   |
	|___|

	*/
	if (min.y < max.y) {
		while (max.y + i < 6) {
			if (Y_Axis(board, min.y, max.y, min.x, ch) && board[max.y + i][min.x] == block) {
				if (X_Axis(board, min.x, max.x, max.y + i, ch)) {
					if (Y_Axis(board, max.y, max.y + i, max.x, ch)) {
						return true;
					}
				}
			}
			else return false;
			i++;
		}
	}
	else {
		while (min.y + i < 6) {
			if (Y_Axis(board, max.y, min.y, max.x, ch) && board[min.y + i][max.x] == block) {
				if (X_Axis(board, min.x, max.x, min.y + i, ch)) {
					if (Y_Axis(board, min.y, min.y + i, min.x, ch)) {
						return true;
					}
				}
			}
			else if (min.y != max.y)
				return false;
			i++;
		}
	}
	return false;
}
bool Uleft(char** a, point A, point B) {
	point min = A, max = B;
	if (A.y > B.y) {
		min = B;
		max = A;
	}
	char** board = extendBoard(a);
	min.x++; min.y++;
	max.x++; max.y++;
	char ch = board[min.y][min.x];


	int i = 0;
	/*
	 ________
	|
	|________
	*/
	if (min.x < max.x) {
		while (min.x - i >= 0) {
			if (X_Axis(board, max.x, min.x, max.y, ch) && board[max.y][min.x - i] == block) {
				if (Y_Axis(board, min.y, max.y, min.x - i, ch)) {
					if (X_Axis(board, min.x, min.x - i, min.y, ch))
						return true;
				}
			}
			else return false;
			i++;
		}
	}
	else {
		while (max.x - i >= 0) {
			if (X_Axis(board, max.x, min.x, min.y, ch) && board[min.y][max.x - i] == block) {
				if (Y_Axis(board, min.y, max.y, max.x - i, ch)) {
					if (X_Axis(board, max.x, max.x - i, max.y, ch))
						return true;
				}
			}
			else if (min.x != max.x)
				return false;
			i++;
		}
	}
	return false;
}
bool Uborder(char** board, point A, point B) {
	if ((A.y == 0 && B.y == 0) || (A.x == 0 && B.x == 0))
		return true;
	if ((A.y == 3 && B.y == 3) || (A.x == 3 && B.x == 3))
		return true;
	return false;
}

bool Udown(char** a, point A, point B) {
	point min = A, max = B;
	if (A.x > B.x) {
		min = B;
		max = A;
	}
	char** board = extendBoard(a);
	min.x++; min.y++;
	max.x++; max.y++;
	char ch = board[min.y][min.x];

	int i = 0;
	/*
	_______
	|     |
	|	  |
	|	  |
	*/
	if (min.y < max.y) {
		while (min.y - i >= 0) {
			if (Y_Axis(board, min.y, max.y, max.x, ch) && board[min.y - i][max.x] == block) {
				if (X_Axis(board, min.x, max.x, min.y - i, ch)) {
					if (Y_Axis(board, min.y, min.y - i, min.x, ch)) {
						return true;
					}
				}
			}
			else return false;
			i++;
		}
	}
	else {
		while (max.y - i >= 0) {
			if (Y_Axis(board, max.y, min.y, min.x, ch) && board[max.y - i][min.x] == block) {
				if (X_Axis(board, min.x, max.x, max.y - i, ch)) {
					if (Y_Axis(board, max.y, max.y - i, max.x, ch)) {
						return true;
					}
				}
			}
			else if (min.y != max.y)
				return false;
			i++;
		}
	}
	return false;
}
bool equalPoint(char** board, point A, point B) 
{
	if (A.x == B.x && A.y == B.y)
		return false;
	if ((board[A.y][A.x] == board[B.y][B.x]))
		return true;
	return false;
}
bool U_L_Matching(char** board, point A, point B) 
{
	if (U_L_horizontal(board, A, B))
		return true;
	else if (U_L_Vertical(board, A, B))
		return true;
	else if (Uleft(board, A, B))
		return true;
	else if (Uborder(board, A, B))
		return true;
	else if (Udown(board, A, B))
		return true;
	return false;
}

bool checkEndGame(char** board, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != block)
				return false;
		}
	}
	return true;
}