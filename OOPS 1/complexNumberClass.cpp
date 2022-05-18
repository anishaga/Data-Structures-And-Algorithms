#include <bits/stdc++.h>
using namespace std;

class ComplexNumber
{
private:
    int real;
    int imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void printComplexNum()
    {
        cout << real << " + i" << imaginary << endl;
    }

    void addComplexNum(ComplexNumber c)
    {
        this->real = this->real + c.real;
        this->imaginary = this->imaginary + c.imaginary;
    }

    void mulComplexNum(ComplexNumber c)
    {
        int x = ((this->real) * (c.real)) - ((this->imaginary) * (c.imaginary));
        this->imaginary = ((this->real) * (c.imaginary)) + ((this->imaginary) * (c.real));
        this->real = x;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int r1, i1;
    cin >> r1 >> i1;
    ComplexNumber c1(r1, i1);

    int r2, i2;
    cin >> r2 >> i2;
    ComplexNumber c2(r2, i2);

    int op;
    cin >> op;

    if (op == 1)
    {
        c1.addComplexNum(c2);
    }
    else
    {
        c1.mulComplexNum(c2);
    }

    c1.printComplexNum();
    // c2.printComplexNum();

    return 0;
}
