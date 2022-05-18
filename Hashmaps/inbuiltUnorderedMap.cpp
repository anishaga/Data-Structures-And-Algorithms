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

    // Insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    ourMap["def"] = 2;

    // Search
    cout <<"Size: "<<ourMap.size()<<endl;
    cout << ourMap["abc"] << endl;
    cout<< ourMap.at("def")<< endl;
    cout <<"Size: "<<ourMap.size()<<endl;

    //Trying To Search At Index Which Is Not Allocated By Us
    // cout<< ourMap.at("ghi")<< endl; // Gives Error: std::out_of_range
    cout << ourMap["ghi"]<< endl;   // Adds A Zero


    //Check Presence
    if (ourMap.count("ghi") == 1)
    {
        cout <<"ghi is present" << endl;
    }

    //Delete

    ourMap.erase("ghi");
    cout <<"Size: "<<ourMap.size()<<endl;
    if (ourMap.count("ghi") > 0)
    {
        cout <<"ghi is present" << endl;
    }

    return 0;
}