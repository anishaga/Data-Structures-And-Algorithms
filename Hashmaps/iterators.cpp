#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    unordered_map<string, int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc1"] = 2;
    ourMap["abc2"] = 3;
    ourMap["abc3"] = 4;
    ourMap["abc4"] = 5;
    ourMap["abc5"] = 6;

    // Iterator 
    unordered_map<string, int>::iterator it = ourMap.begin();
    while (it != ourMap.end())
    {
        cout << "Key: " << it->first << ", " << "Value: " << it->second << endl;
        it++;
    }

    // Find
    unordered_map<string, int>::iterator it2 = ourMap.find("abc");
    ourMap.erase(it2);

    return 0;
}