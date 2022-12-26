#include<iostream>
using namespace std;

class twostack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    twostack(int s){
        s = size;
        top1 = -1;
        top2 = s;
        arr new int[s];
    }

    void push1(int element){
        if(top2 - top1 > 1){
            top1++;
            arr[top]1 = element
        }
        else{
            cout << "Stack Overflow" << endl;

        }
    }

    void push2(int element){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop1(){
        if(top1 > -1){
            top1--;
        }
        else{
            cout << "Stack underflow" << endl;
        }
    }

    void pop2(){
        if(top1 < 1){
            top2++;
        }
        else{
            
            cout << "Stack underflow" << endl;
        }
    }




};

int main(){
    
    return 0;
}