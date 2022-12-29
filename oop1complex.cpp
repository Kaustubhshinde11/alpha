#include <iostream>
using namespace std;

class complex
{
    float r;
    float i;

public:
    complex()
    {
        r = 0;
        i = 0;
    }

    complex operator+(complex);
    complex operator*(complex);

    friend istream &operator>>(istream &input, complex &t)
    {
        cout << "Enter the real part: ";
        input >> t.r;
        cout << "Enter the imaginary part: " << endl;
        input >> t.i;
    }
    friend ostream &operator<<(ostream &output, complex &t)
    {
        output << t.r << " + " << t.i << "i" << endl;
    }
};

complex complex::operator+(complex C)
{
    complex temp;
    temp.r = r + C.r;
    temp.i = i + C.i;
    return temp;
}

complex complex::operator*(complex C)
{
    complex temp;
    temp.r = (r * C.r) - (i * C.i);
    temp.i = (i * C.r) + (r * C.i);
    return temp;
}

int main()
{
    complex c1, c2, c3, c4;
    cout << "Enter the first number: " << endl;
    cin >> c1;
    cout << "Enter the second number: " << endl;
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "The addition of both complex numbers is: " << c3 << endl;
    cout << "The multiplication of both complex numbers is: " << c4 << endl;
    return 0;
}