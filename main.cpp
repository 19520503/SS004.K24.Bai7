#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <cstdio>
#include "console.h"
#define swap(type, a, b) {type temp = a; a = b; b = temp; }

using namespace std;
int d = 0;
int gm = 0;
int v = 0;
char a;

enum Trangthai { UP, RIGHT, DOWN, LEFT, ENTER, BACK, EXIT };
HANDLE hConsoleColor;

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
    int x,y;
};
struct fruit
{
    Toado td;
};
struct Snake
{
    Toado dot[100];
    int n;
    Trangthai tt;
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

        int key=getch();
        if ( (key==119) || (key==87) || (key== 72 ) ) return UP;
        if ( (key==83) || (key==115) || (key == 80 ) )return DOWN;
        if ( key==13) return ENTER;

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

int menu()
{
    //SetConsoleTextAttribute(hConsoleColor, 30);
    int tt = 0;
    int mau[6];
    for (int i = 0; i < 7; i++)
    {
        mau[i] = 14;
    }
    mau[tt] = 30;
    while (1)
    {
        system("cls");
        //putchar('aa');
        SetConsoleTextAttribute(hConsoleColor, 11);

        gotoxy(50, 15);
        SetConsoleTextAttribute(hConsoleColor, mau[0]);
        printf("Bat dau");
        cout << endl;

        gotoxy(50, 16);
        SetConsoleTextAttribute(hConsoleColor, mau[1]);
        printf("Tuy chinh");
        cout << endl;

        gotoxy(50, 17);
        SetConsoleTextAttribute(hConsoleColor, mau[2]);
        printf("Cach choi");
        cout << endl;

        gotoxy(50, 18);
        SetConsoleTextAttribute(hConsoleColor, mau[3]);
        printf("Bang diem");
        cout << endl;

        gotoxy(50, 19);
        SetConsoleTextAttribute(hConsoleColor, mau[4]);
        printf("Thong tin nhom");
        cout << endl;

        gotoxy(50, 20);
        SetConsoleTextAttribute(hConsoleColor, mau[5]);
        printf("Thoat");
        cout << endl;

        Trangthai trangthai = key1();
        switch (trangthai)
        {
        case UP:
        {
            tt--;
            if (tt <= 0) tt = 0;
            Beep(900, 50);
            break;
        }
        case DOWN:
        {
            tt++;
            if (tt >= 5) tt = 5;
            Beep(900, 50);
            break;
        }
        case ENTER: {Beep(900, 50); Beep(900, 50); Beep(900, 50);  return tt; }

        }
        SetConsoleTextAttribute(hConsoleColor, 14);
        for (int i = 0; i < 7; i++)
        {
            mau[i] = 14;
        }
        mau[tt] = 30;
    }
}

void khoitao(Snake& snake, fruit& hq)
{
    snake.n = 3;
    snake.dot[0].x = 1;
    snake.dot[0].y = 1;
    snake.dot[1].x = 1;
    snake.dot[1].y = 1;
    snake.dot[2].x = 1;
    snake.dot[2].y = 1;
    snake.tt = RIGHT;

    hq.td.x = rand() % 70 + 1;
    hq.td.y = rand() % 20 + 1;
}

void Print(Snake& snake, fruit& hq, int& o1)
{

    gotoxy(hq.td.x, hq.td.y);
    SetConsoleTextAttribute(hConsoleColor, 12);
    putchar(1);
    for (int i = 0; i < snake.n; i++)
    {
        gotoxy(snake.dot[i].x, snake.dot[i].y);
        if (i == 0)
        {
            SetConsoleTextAttribute(hConsoleColor, 15);
            putchar(220);
        }
        else
            if (i < snake.n - 2)
            {
                SetConsoleTextAttribute(hConsoleColor, o1 + 2);
                putchar(178);
            }
            else
                putchar(' ');

    }
}

int xuly(Snake& snake, fruit& hq)
{
    if ((snake.dot[0].x == hq.td.x) && (snake.dot[0].y == hq.td.y))
    {
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        snake.n++;
        Beep(900, 50);
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        for (int i = snake.n - 1; i > 0; i--)
        {
            snake.dot[i] = snake.dot[i - 1];
        }
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        if ((snake.tt == LEFT) && (snake.tt != RIGHT))
            snake.dot[0].x--;

        if ((snake.tt == RIGHT) && (snake.tt != LEFT))
            snake.dot[0].x++;

        if ((snake.tt == UP) && (snake.tt != DOWN))
            snake.dot[0].y--;

        if ((snake.tt == DOWN) && (snake.tt != UP))
            snake.dot[0].y++;
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        hq.td.x = rand() % 70 + 1;
        hq.td.y = rand() % 20 + 1;
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        return 0;
    }
    if ((snake.dot[0].x < 1) || ((snake.dot[0].y) == 0) || (snake.dot[0].x == 70) || ((snake.dot[0].y) == 21))
        return -1;
    for (int i = 1; i < snake.n - 2; i++)
    {
        if ((snake.dot[0].x == snake.dot[i].x) &&
            (snake.dot[0].y == snake.dot[i].y))
            return -1;
    }
}

void control(Snake& snake, fruit& hq)
{

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    for (int i = snake.n - 1; i > 0; i--)
    {
        snake.dot[i] = snake.dot[i - 1];
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    if (snake.tt == LEFT)
        snake.dot[0].x--;

    if (snake.tt == RIGHT)
        snake.dot[0].x++;

    if (snake.tt == UP)
        snake.dot[0].y--;

    if (snake.tt == DOWN)
        snake.dot[0].y++;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    if (kbhit())
    {
        int key = _getch();
        if (((key == 'a') || (key == 75) || (key == 'A')) && (snake.tt != RIGHT))
            snake.tt = LEFT;

        else if (((key == 's') || (key == 80) || (key == 'S')) && (snake.tt != UP))
            snake.tt = DOWN;

        else if (((key == 'd') || (key == 77) || (key == 'D')) && (snake.tt != LEFT))
            snake.tt = RIGHT;

        else if (((key == 'w') || (key == 72) || (key == 'W')) && (snake.tt != DOWN))
            snake.tt = UP;

    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
}

void quickSort(int* diem, string* ten, int l, int r)
{
    srand(time(NULL));
    int key = diem[l + rand() % (r - l + 1)];
    //int key = a[(l+r)/2];
    int i = l, j = r;

    while (i <= j)
    {
        while (diem[i] > key) i++;
        while (diem[j] < key) j--;
        if (i <= j)
        {
            if (i < j)
            {
                swap(int, diem[i], diem[j]);
                swap(string, ten[i], ten[j]);
            }
            i++;
            j--;
        }
    }

    if (l < j) quickSort(diem, ten, l, j);
    if (i < r) quickSort(diem, ten, i, r);
}

void record(string& s, int& n)
{
    string ten[11];
    int diem[11];
    ten[10] = s;
    diem[10] = n;
    ifstream f;
    f.open("record.txt");
    for (int i = 0; i < 10; i++)
    {
        f >> ten[i] >> diem[i];
    }
    f.close();
    quickSort(diem, ten, 0, 10);
    gotoxy(30, 1);
    cout << "BANG DIEM";
    gotoxy(20, 2);
    cout << "TEN";
    gotoxy(40, 2);
    cout << "DIEM SO";
    for (int i = 0; i < 10; i++)
    {
        gotoxy(20, i + 3);
        cout << i + 1 << " " << ten[i];
        gotoxy(40, i + 3);
        cout << diem[i] << endl;
    }
    ofstream f1;
    f1.open("record.txt");
    for (int i = 0; i < 10; i++)
    {
        f1 << ten[i] << "  " << diem[i] << endl;
    }
    f1.close();
}

void scoreboard()
{
    string ten[11];
    int diem[11];
    ifstream f;
    f.open("record.txt");
    for (int i = 0; i < 10; i++)
    {
        f >> ten[i] >> diem[i];
    }
    f.close();
    gotoxy(30, 1);
    cout << "BANG DIEM";
    gotoxy(20, 2);
    cout << "TEN";
    gotoxy(40, 2);
    cout << "DIEM SO";
    for (int i = 0; i < 10; i++)
    {
        gotoxy(20, i + 3);
        cout << i + 1 << " " << ten[i];
        gotoxy(40, i + 3);
        cout << diem[i] << endl;
    }
    SetConsoleTextAttribute(hConsoleColor, 7);
}


int main()
{//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 1);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    ifstream f2;
    int l, o1, o2;
    f2.open("LO.txt");
    f2 >> l >> o1 >> o2;
    f2.close();
    int LTV = 0;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    loading();
    while (1)
    {
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        if (l == 0) LTV = 200;
        if (l == 1) LTV = 150;
        if (l == 2) LTV = 50;
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        SetConsoleTextAttribute(hConsoleColor, 13);
        int vi = 0;
        int v = menu();
        switch (v)
        {
        case 0:
        {
            int v1 = 0;
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
            Sleep(500);
            system("cls");
            SetConsoleTextAttribute(hConsoleColor, 9);
            cout << "BAT DAU!";
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
            srand(time(NULL));
            Snake snake;
            fruit hq;
            khoitao(snake, hq);
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
            while (v1 == 0)
            {
                Sleep(500);
                d = 0;
                gm = 0;
                system("cls");
                srand(time(NULL));
                Snake snake;
                fruit hq;
                khoitao(snake, hq);
                Background();
                while (1)
                {

                    Print(snake, hq, o1);
                    control(snake, hq);
                    gm = xuly(snake, hq);
                    if (gm == 0)
                    {
                        d++;
                    }
                    gotoxy(80, 15);
                    SetConsoleTextAttribute(hConsoleColor, 14);
                    cout << "Diem:" << d << endl;
                    if (gm == -1)
                    {
                        gotoxy(80, 16);
                        cout << "Ban thua roi ahihi" << endl;
                        gotoxy(80, 17);
                        //cout<<"Diem Cua Ban la:"<<d<<"   "<<endl;
                        cout << "Nhan Enter";
                        while (_getch() != 13);
                        break;
                    }
                    Sleep(LTV);
                }
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
                gotoxy(80, 17);
                cout << "Ban co muon tiep tuc khong? (Y/N) :   ";
                char q;
                gotoxy(114, 17);
                cin >> q;
                if ((q == 'Y') || (q == 'y'))
                    v1 = 0;
                if ((q == 'N') || (q == 'n'))
                    v1 = 1;
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
            }
            gotoxy(50, 30);
            system("cls");
            string s;
            int n = d;
            cout << "Nhap ten cua ban: ";
            cin >> s;
            //cout<<n;
            system("cls");
            record(s, n);
            //cout<<endl<<"Press any key to back Menu";
            while (_getch() != 8) break;

            break;
        }
        case 1:
        {
            system("cls");
            options(l, o1, o2);
            break;
        }

        case 2:
        {
            Sleep(500);
            system("cls");
            SetConsoleTextAttribute(hConsoleColor, 11);
            Rules();
            //cout<<endl<<"Press any key to back Menu";
            while (_getch() != 13) break;
            break;

        }
        case 3:
        {
            Sleep(500);
            system("cls");
            SetConsoleTextAttribute(hConsoleColor, 11);
            scoreboard();
            //cout<<endl<<"Press any key to back Menu";
            while (_getch() != 8) break;
            //system("cls");
            SetConsoleTextAttribute(hConsoleColor, 30);
            break;
        }
        case 4:
        {
            Sleep(500);
            system("cls");
            SetConsoleTextAttribute(hConsoleColor, 11);
            Introduce();
            //cout<<endl<<"Press any key to back Menu";
            while (_getch() != 8) break;
            break;
        }
        case 5:
        {
            vi = 1;
            break;
        }


        }
        if (vi == 1)
        {
            system("cls");
            break;
        }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    ofstream f3;
    f3.open("LO.txt");
    f3 << l << endl << o1 << endl << o2;
    f3.close();
    return 0;
    return 0;
}
