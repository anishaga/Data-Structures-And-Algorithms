#include <iostream>
#include <string>
using namespace std;

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s = "abc";
    cout << s.size() << endl;

    s.erase(1,1);
    cout << s;
   

    return 0;
}