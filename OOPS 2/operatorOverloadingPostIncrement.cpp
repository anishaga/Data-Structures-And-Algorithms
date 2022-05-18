#include <bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    int num;
    int denom;

    Fraction(int num, int denom)
    {
        this->num = num;
        this->denom = denom;
    }
    void printFraction()
    {
        cout<<num<<"/"<<denom<<endl;
    }
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
    Fraction operator++(int)
    {
        Fraction fnew(num,denom);
        num = num + denom;
        simplify();
        fnew.simplify();
        return fnew;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Fraction f1(10,2);
    Fraction f3 = f1++;
    f3.printFraction();
    f1.printFraction();

    return 0;
}
