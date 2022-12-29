#include<iostream>
#include<graphics.h>
using namespace std;

inline void window() {
    rectangle(200, 200, 400, 400);
}

string code(float x, float y){

    string c = "0000";

    if(y < 200) c[0] = '1'; // up
    if(x > 400) c[1] = '1'; // right
    if(y > 400) c[2] = '1'; // down
    if(x < 200) c[3] = '1'; // left

    return c;
}

void clipping(string c, float &x, float &y, float m) {

    // up
    if(c[0] == '1'){
        x = x + (200 - y) / m;
        y = 200;
    }
    
    // right
    if(c[1] == '1'){
        x = 400;
        y = y + (x - 400) * m;
    }

    // down
    if(c[2] == '1'){
        x = x + (y - 400) / m;
        y = 400;
    }

    // left
    if(c[3] == '1'){
        x = 200;
        y = y + (200 - x) * m;
    }
}

int main() {

    float x1, y1, x2, y2;
    cout << "Enter line co-ordinates: ";
    cin >> x1 >> y1 >> x2 >> y2;

    float m = (y2 - y1) / (x2 - x1);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Before Clipping: " << endl;
    window();
    line(x1, y1, x2, y2);
    delay(4000);
    cleardevice();

    string c = code(x1, y1);
    string d = code(x2, y2);
    clipping(c, x1, y1, m);
    clipping(d, x2, y2, m);

    cout << "After Clipping: " << endl;
    window();
    line(x1, y1, x2, y2);
    
    getch();

    return 0;
}