#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int i=69;
    cout<<"Value: "<<i<<endl;
    cout<<"Address: "<<&i<<endl;

    int *ip = &i;
    cout<<ip<<endl;

    cout<<"Value Using Pointer: "<<*ip<<endl;

    // float f=69.6;
    // float *fp  = &f;
    // cout<<fp<<endl;
 
    // double d = 6969.6969;
    // double *dp = &d;
    // cout<<dp<<endl;

    return 0;
}