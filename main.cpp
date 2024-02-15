#include <iostream>
#include <iomanip>
#include <windows.h>
#include "algorithm.h"
#include "board.h"
#include "textAnimation.h"
using namespace std;

char blockmain = 32;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void inputPoint(point& A, point& B) {
	
	SetConsoleTextAttribute(h, 9);
	cout << "\tPoint of first Pokemon\n";
	cout << "\tX Y (e.g 2 0): "; 
	SetConsoleTextAttribute(h, 15); 
	cin >> A.x >> A.y;
	SetConsoleTextAttribute(h, 9);
	cout << "\tPoint of second Pokemon\n";
	cout << "\tX Y (e.g 2 1): ";  
	SetConsoleTextAttribute(h, 15); 
	cin >> B.x >> B.y;
	SetConsoleTextAttribute(h, 10);
}
bool pikachuMatch(char** board, point A, point B) {
	if (equalPoint(board, A, B) == false)
		return false;
	if (IMatching(board, A, B))
		return true;
	else if (ZMatching(board, A, B))
		return true;
	else if (U_L_Matching(board, A, B))
		return true;
	return false;
}
void StandardMode() {
	system("cls");
	int rows = 4, cols = 4;
	
	SetConsoleTextAttribute(h, 10);	
	printText2();
	SetConsoleTextAttribute(h, 15);
	char** board = generateBoard(rows, cols);
	
	printBoard(board, rows, cols);
	SetConsoleTextAttribute(h, 10);
	printArt();
	point A, B;
	bool flg = false;
	while (1) {
		if (flg) {
			SetConsoleTextAttribute(h, 12);
			cout << "\n\tTry again!";
			flg = false;
		}
		cout << "\n";
		inputPoint(A, B);
		if (pikachuMatch(board, A, B)) {
			board[A.y][A.x] = blockmain;
			board[B.y][B.x] = blockmain;
			system("cls");
			SetConsoleTextAttribute(h, 10);
			printText2();
			SetConsoleTextAttribute(h, 15);
			printBoard(board, rows, cols);
			SetConsoleTextAttribute(h, 10);
			printArt();
		}
		else {
			flg = true;
			system("cls");
			SetConsoleTextAttribute(h, 10);
			printText2();
			SetConsoleTextAttribute(h, 15);
			printBoard(board, rows, cols);
			SetConsoleTextAttribute(h, 10);
			printArt();
		}
		if (checkEndGame(board,rows,cols))
		{
			system("cls");
			SetConsoleTextAttribute(h, 11);
			printText4();
			cout << endl;
			SetConsoleTextAttribute(h, 9);
			textAnimation("Congratulation! you have completed the game.");
			SetConsoleTextAttribute(h, 7);
			return;
		}
	}
}
void Menu() {
	int choice;
	printText1();
	SetConsoleTextAttribute(h, 10);
	cout << setw(45) << endl; textAnimation("(^_^)Hey, welcome to pikachu matching game!(^_^)"); cout << endl;
	cout << endl;
	cout << setw(55);
	SetConsoleTextAttribute(h, 14);
	textAnimation2(" ====================");
	cout << setw(55);
	textAnimation2("|| 1.Standard mode  ||");
	cout << setw(55);
	textAnimation2("|| 2.Exit           ||");
	cout << setw(55);
	textAnimation2(" ====================");
	cout << setw(74) << "Enter your choice: ";
	SetConsoleTextAttribute(h, 15);
	cin >> choice;
	if (choice == 1)
		StandardMode();
	else if (choice == 2)
		return;
	else
	{
		system("cls");
		cout << "Enter your choice again!\n";
		Menu();
	}

}
int main() {
	Menu();
	//StandardMode();
	

	return 0;
}
/*
1: Blue
2 : Green
3 : Суan
4 : Red
5 : Purple
6 : Yellow(Dark)
7 : Default white
8 : Gray / Grey
9 : Bright blue
10 : Brigth green
11 : Bright cyan
12 : Bright red
13 : Pink / Magenta
14 : Yellow
15 : Bright white
*/