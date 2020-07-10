#include <iostream>
#include <conio.h>
#include <cstdio>
#include "console.h"

using namespace std;

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
struct Toado
{
	int x, y;
};
struct fruit
{
	Toado td;
};

void loading()
{
	gotoxy(25, 20);
	putchar(201);

	for (int i = 1; i < 78; i++)
		putchar(205);

	putchar(187);

	gotoxy(25, 21);
	putchar(186);

	gotoxy(103, 21);
	putchar(186);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	gotoxy(25, 22);
	putchar(200);

	for (int i = 1; i < 78; i++)
		putchar(205);

	putchar(188);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	gotoxy(60, 21);
	SetConsoleTextAttribute(hConsoleColor, 8);
	cout << "Loading";
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	SetConsoleTextAttribute(hConsoleColor, 9);
	gotoxy(26, 19);
	cout << "Nhan phim di chuyen de di chuyen, Enter de chon va bat ki phim nao de tro lai";
	SetConsoleTextAttribute(hConsoleColor, 15);
	gotoxy(26, 21);
	for (int i = 0; i < 77; i++)
	{
		int v = rand() % 100;
		Sleep(v);
		putchar(247);
	}
}
void Introduce()
{
	gotoxy(0, 3);
	cout << "Thanh vien: " << endl << endl;//60
	gotoxy(0, 4);
	cout << "           19521097: Luc Tu Van" << endl;
	cout << "           19520538: Duong Minh Hieu" << endl;
	cout << "           19520503: Nguyen Ngoc Quynh Giao" << endl;
	cout << "           19521010: Nguyen Thi Hoai Thuong" << endl;

}

int main()
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 1);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	loading();
	Introduce();
	return 0;
}