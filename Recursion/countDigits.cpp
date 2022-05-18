#include <bits/stdc++.h>
using namespace std;

// int countDigits(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     int count = countDigits (n/10);
//     return count+1;
// }

void countDigits(int n, int *count)
{
    if (n==0)
    {
         return;
    }
   
    (*count)++;
    countDigits(n/10,count);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    int count =0;
    cin >> n;
    //cout << countDigits(n);
    countDigits(n,&count);
    cout << count;
    return 0;
}
