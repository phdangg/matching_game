#include <iostream>
#include <Windows.h>
#include <time.h>
#include "board.h"
#include "algorithm.h"
using namespace std;
void printBoard(char** a, int row, int col) 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\n\t    ";
	for (int i = 0; i < col; i++) {
		SetConsoleTextAttribute(h, 15);
		cout << i;
		SetConsoleTextAttribute(h, 14);
		cout << "       ";
	}
	cout << "\n";
	for (int i = 0; i < row; i++)
	{
		cout << "\t";
		for (int j = 0; j < col; j++) {
			cout << " -------";
		}
		cout << "\n";
		for (int j = 0; j <= col; j++) {
			cout << "\t|";
		}
		cout << "\n    ";
		SetConsoleTextAttribute(h, 15);
		cout << i;
		SetConsoleTextAttribute(h, 14);
		cout << "   ";
		for (int j = 0; j < col; j++) {
			cout << "|   ";
			SetConsoleTextAttribute(h, 15);
			cout << a[i][j];
			SetConsoleTextAttribute(h, 14);
			cout << "   ";
		}
		cout << "|";
		cout << "\n";
		for (int j = 0; j <= col; j++) {
			cout << "\t|";
		}
		cout << "\n";
	}
	cout << "\t";
	for (int j = 0; j < col; j++) {
		cout << " -------";
	}

}

char** generateBoard(int row, int col)
{

	srand((int)time(0));
	char** a = new char* [row];

	for (int i = 0; i < row; i++)
	{
		a[i] = new char[col];
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = 0;

	int cnt = 0;
	for (char i = 'A'; ; i++)
	{
		int m, n;

		while (true)
		{
			m = rand() % row;
			n = rand() % col;

			if (a[m][n] == 0)
			{
				a[m][n] = i;
				cnt++;
				break;
			}
		}

		while (true)
		{
			m = rand() % row;
			n = rand() % col;

			if (a[m][n] == 0)
			{
				a[m][n] = i;
				cnt++;
				break;
			}
		}
		if (cnt == row * col)
			break;
	}
	return a;
}
