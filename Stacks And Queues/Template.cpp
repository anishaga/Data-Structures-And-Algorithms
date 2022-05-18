#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
class Pair
{
    T x;
    U y;

    public:
    
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }

    void setY(U y)
    {
        this->y = y;
    }

    U getY()
    {
        return y;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    Pair<int,double> p1;

    p1.setX(100);
    p1.setY(100.34);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<double, int> p2;

    p2.setX(100.34);
    p2.setY(100);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    return 0;
}

