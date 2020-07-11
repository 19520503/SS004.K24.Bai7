#include <iostream>
#include <conio.h>
#include <cstdio>
#include "console.h"

using namespace std;

string option[3] = { "De", "Vua", "Kho" };
int CL[14] = { 2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
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

int options(int& l, int& o1, int& o2)
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int mau[3];
	for (int i = 0; i < 3; i++) mau[i] = 14;
	mau[l] = 63;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int LS = 0;
	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 13);
		if (LS == 0)
			cout << "Cap do:  <==" << endl;
		else cout << "Cap do:" << endl;

		for (int i = 0; i < 3; i++)
		{
			SetConsoleTextAttribute(hConsoleColor, mau[i]);
			gotoxy(10 * i, 1);
			cout << option[i];
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		gotoxy(0, 3);
		SetConsoleTextAttribute(hConsoleColor, 13);
		if (LS == 1)
			cout << "Mau sac:  <==" << endl;
		else
			cout << "Mau sac" << endl;
		for (int i = 0; i < 14; i++)
		{
			SetConsoleTextAttribute(hConsoleColor, CL[i]);
			gotoxy(5 * i, 4);
			cout << (char)254 << (char)254;
		}
		SetConsoleTextAttribute(hConsoleColor, 13);
		gotoxy(0, 8);
		if (LS == 2)
			cout << "LUU LAI:   <=="; else cout << "LUU LAI";
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		Trangthai trangthai = key2();
		switch (trangthai)
		{
		case RIGHT:
		{
			if (LS == 0)
			{
				mau[l] = 14;
				l--;
				if (l <= 0) l = 0;
				mau[l] = 63;
				Beep(900, 50);
				break;
			}
			else
				if (LS == 1)
				{
					CL[o1] = o1 + 2;
					o1--;
					if (o1 <= 0) o1 = 0;
					CL[o1] = o1 + 2 + 16;
					Beep(900, 50);
					break;
				}
			if (LS == 2) break;
		}
		case LEFT:
		{
			if (LS == 0)
			{
				mau[l] = 14;
				l++;
				if (l >= 2) l = 2;
				mau[l] = 63;
				Beep(900, 50);
				break;
			}
			else
				if (LS == 1)
				{
					CL[o1] = o1 + 2;
					o1++;
					if (o1 >= 13) o1 = 13;
					CL[o1] = o1 + 2 + 16;
					Beep(900, 50);
					break;
				}
			if (LS == 2) break;

		}
		case UP:
		{
			LS--;
			if (LS == 1)
			{
				mau[l] = 63;
				CL[o1] = o1 + 2 + 16;
				Beep(900, 50);
			}

			if (LS <= 0) LS = 0;
			if (LS == 0)
			{
				CL[o1] = o1 + 2 + 16;
				mau[l] = 63;
				Beep(900, 50);
				LS = 0;
			}
			break;

		}

		case DOWN:
		{
			LS++;
			if (LS >= 2) LS = 2;
			if (LS == 1)
			{
				mau[l] = 63;
				CL[o1] = o1 + 2 + 16;
				Beep(900, 50);
			}

			if (LS == 2)
			{
				CL[o1] = o1 + 2 + 16;
				gotoxy(0, 8);
				cout << "LUU LAI:   <==";
			}


			break;

		}
		case ENTER:
		{
			Beep(900, 50);
			if (LS == 0) { mau[l] = 63; LS++; }
			else
				if (LS == 1) { CL[o1] = o1 + 2 + 16; LS++; }
				else return 0;
		}
		SetConsoleTextAttribute(hConsoleColor, 11);
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

}

int main()
{
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 1);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	loading();
	Introduce();
	Rules();
	return 0;
}