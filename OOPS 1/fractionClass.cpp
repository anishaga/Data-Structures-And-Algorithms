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

    void addFraction(Fraction s)
    {
        this->num = ((this->num) * s.denom) + ((s.num) * (this->denom));
        this->denom = (this->denom) * (s.denom);
        simplify();
    }
};

main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Fraction s1(10, 2);
    Fraction s2(15, 4);

    s1.addFraction(s2);

    s1.printFraction();

    return 0;
}
