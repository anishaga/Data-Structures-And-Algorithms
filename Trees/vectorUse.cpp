#include <iostream>
using namespace std;
#include <vector>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    vector<int> v;

    for (int i=0; i<5; i++)
    {
        v.push_back(i+1);
    }
    v[2] = 200;
    v.at(3) = 300;
    v.pop_back();

    for (int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }


    return 0;
}
