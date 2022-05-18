#include <iostream>
#include <string>
using namespace std;

void printKeyPad(int n, string* s, string output)
{
    if (n==0)
    {
        cout << output << endl;
        return;
    }

    int num = n % 10;
    string temp;
    temp = s[num];
    int size = temp.size();
    int i=0;
    while (i < size)
    {
        printKeyPad(n / 10, s, temp[i] + output);
        i++;
    }
}

void printKeyPad(int n)
{
    string s[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    printKeyPad(n, s, output);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    printKeyPad(n);

    return 0;
}