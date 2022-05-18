#include <bits/stdc++.h>
using namespace std;

int numberOfDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

void getAlpha(int n, string alpha[])
{
    string s[] = {" "," ","abc" ,"def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int i=0;
    while (n!=0)
    {
        int temp = n%10;
        alpha[i]= s[temp];
        i++;
        n=n/10;
    }
}

int seq(string alpha[], string op[])
{
    if(alpha.empty())
    {
        op[0]="";
        return 1;
    }
    string smallString =  alpha.substr(1);
    

    op[index]
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int count = numberOfDigits(n);

    string* alpha = new string[count];
    getAlpha(n, alpha);

    // for(int i=0; i<count; i++)
    // {
    //     cout<<alpha[i]<<endl;
    // }

    int temp = pow(count,4);
    string* op = new string[temp];
    int size = seq(n,op);
    for(int i=0; i<size; i++)
    {
        cout<<op[i];
    }

    return 0;
}