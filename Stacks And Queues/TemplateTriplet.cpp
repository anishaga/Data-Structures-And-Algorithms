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

int
main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Pair<Pair<int,int>,int> p1;
    Pair<int,int> p2;

    p2.setX(10);
    p2.setY(15);

    p1.setX(p2);
    p1.setY(20);

    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY();

    return 0;
}
