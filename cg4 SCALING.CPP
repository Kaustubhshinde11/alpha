#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>

void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C://TURBOC3//BGI");
int x1, y1, x2, y2, x3, y3;
int sx, sy;
cout << "Enter the coordinates ";
cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
line(x1, y1, x2, y2);
line(x2, y2, x3, y3);
line(x3, y3, x1, y1);
cout << "\nEnter scaling factor sx and sy: ";
cin >> sx >> sy;
x1 = x1*sx;
x2 = x2*sx;
x3 = x3*sx;
y1 = y1*sy;
y2 = y2*sy;
y3 = y3*sy;
line(x1, y1, x2, y2);
line(x2, y2, x3, y3);
line(x3, y3, x1, y1);
getch();
closegraph();
}