#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

// DDA
void DDALine(int x1, int y1, int x2, int y2, int color){

    float dx = x2 - x1, dy = y2 - y1;
    float steps = max(abs(dx), abs(dy));

    float xInc = dx / steps, yInc = dy / steps;

    float x = x1, y = y1;
    for (int i=1; i<=steps; i++) {

        // putpixel() function plots a pixel at location (x, y) of specified color
        putpixel(x, y, color);

        x += xInc;
        y += yInc;
    }

}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initializes the graphics system by loading a graphics driver from disk
    cleardevice();

    // Draw Triangle
    DDALine(100, 113, 50, 200, RED);
    DDALine(50, 200, 150, 200, RED);
    DDALine(150, 200, 100, 113, RED);

    // find midpoint of triangle
    int x1 = (100+50+150) / 3;
    int y1 = (113+200+200) / 3;

    setcolor(YELLOW);

    // find out radius of inner circle & draw it
    int r = 50 / sqrt(3); 
    circle(x1, y1, r);

    // find out radius of outer circle & draw it
    int r1 = 100 / sqrt(3);
    circle(x1, y1, r1);

    getch();
    return 0;
}