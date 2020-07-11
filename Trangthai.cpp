#include <iostream>
#include <time.h>
#include <conio.h>
#include <cstdio>
#include "console.h"

using namespace std;

enum Trangthai { UP, RIGHT, DOWN, LEFT, ENTER, BACK, EXIT };
HANDLE hConsoleColor;

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

void Rules()
{
	cout << "\nDieu khien:";
	cout << " Su dung phim mui ten (hoac W, A, S, D) de dieu khien len tren, qua trai, xuong duoi, qua phai de an trai cay" << endl;
	cout << "\nDiem so:";
	cout << "    An trai cay de kiem diem" << endl;
	cout << "\nLuu y :";
	cout << "     Khong de dau ran dung vao duoi hoac tuong. Neu khong, ban se thua" << endl;
}

void Background()
{
	int Height = 20;
	int Width = 70;
	for (int i = 0; i <= Height; i++)
	{
		//1
		if (i == 0)
		{
			for (int j = 0; j <= Width; j++)
			{
				if (j == 0) putchar(201);
				//cout<<"_";
				if (j == Width) putchar(187), cout << endl;
				else gotoxy(j + 1, i), putchar(205);
			}
		};
		//2
		if (i == Height)
		{
			for (int j = 0; j <= Width; j++)
			{

				if (j == 0) putchar(200);
				//cout<<"||";
				if (j == Width) putchar(188), cout << endl;
				//cout<<"||"<<endl;
				else gotoxy(j + 1, i + 1), putchar(205);//cout<<"_";
			}
		}
		//3
		else    for (int j = 0; j <= Width; j++)
		{
			if (j == 0) gotoxy(j, i + 1), putchar(186);//cout<<"||";
			if (j == Width) gotoxy(j + 1, i + 1), putchar(186), cout << endl;//cout<<"||"<<endl;
			else cout << " ";
		}
	}
}

Trangthai key1()
{

	int key = getch();
	if ((key == 119) || (key == 87) || (key == 72)) return UP;
	if ((key == 83) || (key == 115) || (key == 80))return DOWN;
	if (key == 13) return ENTER;

}
Trangthai key2()
{

	int key = getch();
	if ((key == 119) || (key == 87) || (key == 72)) return UP;
	if ((key == 83) || (key == 115) || (key == 80))return DOWN;
	if ((key == 75) || (key == 65) || (key == 97))return RIGHT;
	if ((key == 77) || (key == 68) || (key == 100))return LEFT;
	if (key == 13) return ENTER;

}

int main()
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 1);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	loading();

	return 0;
}