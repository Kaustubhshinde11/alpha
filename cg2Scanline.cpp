#include<iostream>
#include<algorithm>
#include<vector>
#include<graphics.h>
using namespace std;

void scanline(int *xcord, int *ycord, int n){

    int ymax = 0, ymin = 500;
    float m[n], dx, dy;

    for(int i=0; i<n; i++) {
        
        ymax = max(ymax, ycord[i]);
        ymin = min(ymin, ycord[i]);

        dx = xcord[i+1] - xcord[i];
        dy = ycord[i+1] - ycord[i];

        if(dx == 0)
	        m[i] = 0;
        else if(dy == 0)
	        m[i] = 1;
        else
	        m[i] = (float)(dx/dy);
    }

    for(int y=ymin; y<=ymax; y++) {
        
        vector<int> inx;
        for(int i=0; i<n; i++){
	        if((ycord[i] > y && ycord[i+1] <= y) || (ycord[i] <= y && ycord[i+1] > y)){
	            inx.push_back( xcord[i] + (m[i]*(y-ycord[i])) );
	        }
        }

        sort(inx.begin(), inx.end());
	    
        for(int i=0; i<inx.size(); i+=2) {
	        line(inx[i], y, inx[i+1], y);
	        delay(70);
	    }
    }
}

int main() {

    int n;
    cout << "Enter No. of vertices: ";
    cin >> n;

    int *xcord = new int[n+1];
    int *ycord = new int[n+1];
    
    for(int i=0; i<n; i++){
        cout << "Enter Co-ordinates of Vertex: ";
        cin >> xcord[i] >> ycord[i];
    }
    xcord[n] = xcord[0], ycord[n] = ycord[0];

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    for(int i=0; i<n; i++){
        delay(200);
        line(xcord[i], ycord[i], xcord[i+1], ycord[i+1]);
    }

    scanline(xcord, ycord, n);

    closegraph();
    return 0;
}