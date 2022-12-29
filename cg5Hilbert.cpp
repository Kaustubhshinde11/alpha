#include<iostream>
#include<graphics.h>
using namespace std;

/*
2 3 4 1
3 2 1 4
2 3 4 1
2 3 4 1
1 4 3 2
2 3 4
*/

void move(int j, int h, int &x, int &y){

    if(j == 1){
        y -= h;
    }
    else if(j == 2){
        x += h;
    }
    else if(j == 3){
        y += h;
    }
    else if(j == 4){
        x -= h;
    }
    lineto(x, y);
    delay(10);
}

void hilbert(int a2, int a3, int a4, int a1, int i, int h, int &x, int &y){

    if(i <= 0)
        return;

    i--;

    hilbert(a3, a2, a1, a4, i, h, x, y);
    move(a2, h, x, y);
    hilbert(a2, a3, a4, a1, i, h, x, y);
    move(a3, h, x, y);
    hilbert(a2, a3, a4, a1, i, h, x, y);
    move(a4, h, x, y);
    hilbert(a1, a4, a3, a2, i, h, x, y);
}

int main() {
    
    int n, x=100, y=100;
    cout << "Enter the value of n: ";
    cin >> n;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    moveto(x, y);
    hilbert(2, 3, 4, 1, n, 10, x, y);

    delay(10000);
    closegraph();

    return 0;
}