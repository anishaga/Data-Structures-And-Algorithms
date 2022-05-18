#include <bits/stdc++.h>
using namespace std;

int size(char a[])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void pairStar(char a[], int n, char string[], int index)
{
    if (n == 0)
    {
        return;
    }
    if (a[0] == a[1])
    {
        string[index] = a[0];
        index++;
        string[index] = '*';
    }
    else
    {
        string[index] = a[0];
    }
    pairStar(a + 1, n - 1, string, index + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char a[100];
    cin >> a;
    int n = size(a);

    char string[100];
    int index = 0;
    pairStar(a, n, string, index);
    cout << string;
    return 0;
}
