#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "algorithm.h"
using namespace std;


void printArt()
{
	string line = "";
	ifstream filein;
	filein.open("image/pokemon.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{
		int posX = 50, posY = 7;
		while (getline(filein, line))
		{
			gotoxy(posX, posY++);
			cout << line << endl;
		}
	}
}
void printArt2()
{
	string line = "";
	ifstream filein;
	filein.open("image/pokemon2.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{
		while (getline(filein, line))
		{

			cout << line << endl;
		}
	}
}
void printText1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string line = "";
	ifstream filein;
	filein.open("image/welcome.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{
		int linefile = 0;
		while (getline(filein, line))
		{
			SetConsoleTextAttribute(h, 9);
			if(linefile >= 4 && linefile < 8)
				SetConsoleTextAttribute(h, 10);
			else if (linefile >=8)
				SetConsoleTextAttribute(h, 14);
			cout << line << endl;
			linefile++;
		}
	}
}
void printText2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string line = "";
	ifstream filein;
	filein.open("image/standard.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{

		while (getline(filein, line))
		{
			SetConsoleTextAttribute(h, 9);
			cout << line << endl;
		}
	}
}
void printText3()
{
	string line = "";
	ifstream filein;
	filein.open("image/Difficult.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{
		while (getline(filein, line))
		{
			cout << line << endl;
		}
	}
}
void printText4()
{
	string line = "";
	ifstream filein;
	filein.open("image/endgame.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{
		while (getline(filein, line))
		{
			cout << line << endl;
		}
	}
}
void printEndGame()
{
	string line = "";
	ifstream filein;
	filein.open("image/endgame.txt", ios::in);
	if (!filein)
	{
		cout << "cannot open file";
	}
	else
	{
		while (getline(filein, line))
		{
			cout << line << endl;
		}
	}
}
void textAnimation(string a)
{
	for (int i = 0; a[i] != '\0'; ++i)
	{
		for (double k = 0; k < 10000000; ++k)
			;
		cout << a[i];
	}
}
void textAnimation2(string a)
{
	for (int i = 0; a[i] != '\0'; ++i)
	{
		for (double k = 0; k < 10000000; ++k)
			;
		cout << a[i];
	}
	cout << endl;
}
