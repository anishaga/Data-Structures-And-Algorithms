#include <iostream>
using namespace std;

bool isPalindrome(string s, int si, int end)
{
   if (si >= end)
   {
       return 1;
   } 

   if (s[si] != s[end])
   {
       return 0;
   }

   return isPalindrome(s,si+1,end-1);
}  

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    cout <<isPalindrome(s, 0, s.size()-1);
    return 0;
}