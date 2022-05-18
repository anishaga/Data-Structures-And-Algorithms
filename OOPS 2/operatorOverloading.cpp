#include <bits/stdc++.h>
using namespace std;

class Fraction
{
private:
    int num;
    int denom;

public:
    Fraction(int num, int denom)
    {
        this->num = num;
        this->denom = denom;
    }

    // Fraction()
    // {

    // }

    void simplify()
    {
        int minimum = min(num, denom);

        for (int i = minimum; i > 0; i--)
        {
            if (num % i == 0 && denom % i == 0)
            {
                num = num / i;
                denom = denom / i;
                break;
            }
        }
    }
    void printFraction()
    {
        cout << num << "/" << denom << endl;
    }

    Fraction addFraction(Fraction s)
    {
        int x = ((this->num) * s.denom) + ((s.num) * (this->denom));
        int y = (this->denom) * (s.denom);
        Fraction s3(x, y);
        s3.simplify();
        return s3;
    }

    Fraction operator+(Fraction s)
    {
        int x = ((this->num) * s.denom) + ((s.num) * (this->denom));
        int y = (this->denom) * (s.denom);
        Fraction s3(x, y);
        s3.simplify();
        return s3;
    }

    bool operator==(Fraction s)
    {
        this->simplify();
        s.simplify();
        if ((this->num) == s.num && (this->denom) == s.denom)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Fraction s1(10, 2);
    Fraction s2(20, 4);

    // Fraction s3 = s1 + s2; //Copy Constructor

    cout << (s1 == s2);

    // s1.printFraction();
    // s2.printFraction();
    // s3.printFraction();

    return 0;
}
