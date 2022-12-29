#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

void translatereactangle(int p[][2], int T[])
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "C://TURBOC3//BGI");
setcolor(2);
rectangle(p[0][0], p[0][1], p[1][0], p[1][1]);
p[0][0] = p[0][0] + T[0];
p[0][1] = p[0][1] + T[1];
p[1][0] = p[1][0] + T[0];
p[1][1] = p[1][1] + T[1];

rectangle(p[0][0], p[0][1], p[1][0], p[1][1]);
}

void main()
{
clrscr();
int p[2][2] = {50, 80, 180, 130};
int T[] = {50, 25};
translatereactangle(p, T);
delay(1000);
getch();
}