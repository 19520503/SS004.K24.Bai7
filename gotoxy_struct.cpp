#include <iostream>
#include <conio.h>
#include <cstdio>
#include "console.h"

using namespace std;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
struct Toado
{
    int x,y;
};
struct fruit
{
    Toado td;
};

int main()
{
    return 0;
}
