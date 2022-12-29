#include<iostream>
#include<graphics.h>
using namespace std;

int main() {

    int gd = DETECT, gm;
    int x = 20, y = 200, uplimit = 200;
    bool flag = false;
    initgraph(&gd, &gm, NULL);
    while(!kbhit()){
        
        setcolor(RED);
        line(0, 400, 1000, 400);
        if(flag == false){
            x += 1;
            y += 2;
            if(y >= 385)
                flag = true;
        }
        else {
            x += 1;
            y -= 2;
            if(y <= uplimit){
                uplimit += 20;
                flag = false;
            }
        }

        setcolor(YELLOW);
        fillellipse(x, y, 15, 15);
        setfillstyle(2, YELLOW);
        delay(10);
        cleardevice();
    }
    closegraph();
}