#pragma once
struct point {
	int x;
	int y;
};
void gotoxy(short x, short y);
bool X_Axis(char** board, int xA, int xB, int y, char ch);
bool Y_Axis(char** board, int yA, int yB, int x, char ch);
bool IMatching(char** board, point A, point B);
bool ZMatching(char** board, point A, point B);
char** extendBoard(char** a);
bool U_L_horizontal(char** a, point A, point B);
bool U_L_Vertical(char** a, point A, point B);
bool Uleft(char** a, point A, point B);
bool Uborder(char** board, point A, point B);
bool Udown(char** a, point A, point B);
bool checkEndGame(char** board, int row, int col);
bool equalPoint(char** board, point A, point B);
bool U_L_Matching(char** board, point A, point B);

