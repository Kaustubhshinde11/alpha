#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    map<string, int> Marksmap;
    Marksmap["Maharashtra"] = 10101;
    Marksmap["Kerala"] = 102014;
    Marksmap["Japan"] = 550201;
    Marksmap["Goa"] = 469635;
    string s;
    cout << "enter:";
    cin >> s;
    cout << Marksmap[s];

    return 0;
}