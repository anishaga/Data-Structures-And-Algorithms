#include <iostream>
#include <unordered_map>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int *longestConsecutive(int a[], int n)
{
    unordered_map<int, bool> ourMap;

    for (int i = 0; i < n; i++)
    {
        ourMap[a[i]] = 1;
    }

    unordered_map<int, bool>::iterator it = ourMap.begin();

    int *ans = new int[2];
    int max = 0;
    int maxNum;
    int minNum;
    while (it != ourMap.end())
    {
        int currentLen = 1;

        if (it->second == 1)
        {
            int num = it->first + 1;
            while (1)
            {
                if (ourMap.count(num) == 1)
                {
                    ourMap[num] = 0;
                    currentLen++;
                    num++;
                }
                else
                {
                    maxNum = num - 1;
                    break;
                }
            }

            num = it->first - 1;
            while (1)
            {
                if (ourMap.count(num) == 1)
                {
                    ourMap[num] = 0;
                    currentLen++;
                    num--;
                }
                else
                {
                    minNum = num + 1;
                    break;
                }
            }

            if (currentLen > max)
            {
                max = currentLen;
                ans[0] = minNum;
                ans[1] = maxNum;
            }
        }
        it++;
    }

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[100];

    takeInputArray(a, n);
    int *ans = longestConsecutive(a, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}