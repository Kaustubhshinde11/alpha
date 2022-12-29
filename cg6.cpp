#include<iostream>
#include<graphics.h>
using namespace std;

void sunrise(int x1, int y1, int x2, int y2){

    for(int i=x1, j=y1; i<=x2, j>=y2; i+=5, j-=5){
        delay(120);
        cleardevice();
        if(i <= 150){
            setcolor(YELLOW);
            setfillstyle(1, YELLOW);
        }
        else {
            setcolor(GREEN^RED);
            setfillstyle(1, GREEN^RED);
        }
        fillellipse(i, j, 20, 20);
    }
}

void sunset(int x1, int y1, int x2, int y2){

    for(int i=x1, j=y1; i<=x2, j<=y2; i+=5, j+=5){
        delay(120);
        cleardevice();
        if(i <= 450){
            setcolor(GREEN^RED);
            setfillstyle(1, GREEN^RED);
        }
        else {
            setcolor(YELLOW);
            setfillstyle(1, YELLOW);
        }
        fillellipse(i, j, 20, 20);
    }
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(BLUE);

    sunrise(50, 300, 300, 50);

    delay(1000);
    cleardevice();
    setcolor(RED);
    setfillstyle(1 ,RED);
    fillellipse(300, 50, 20, 20);
    delay(150);

    sunset(300, 50, 550, 300);

    closegraph();

    return 0;
}