#include <bits/stdc++.h>
using namespace std;

int AllIndexesRecursive(int input[], int size, int x, int output[])
{

    if (size == 0)
    {
        return 0;
    }

    int smallAns = AllIndexesRecursive(input + 1, size - 1, x, output);

    // If the element at index 0 is equal to x then add 1 to the array values and shift them right by 1 step
    if (input[0] == x)
    {
        for (int i = smallAns - 1; i >= 0; i--)
        {
            output[i + 1] = output[i] + 1;
        }

        // Put the start index in front of the array
        output[0] = 0;
        smallAns++;
    }
    else
    {

        // If the element at index 0 is not equal to x then add 1 to the array values
        for (int i = smallAns - 1; i >= 0; i--)
        {
            output[i] = output[i] + 1;
        }
    }
    return smallAns;
}

void AllIndexes(int input[], int n, int x)
{
    int output[n];
    int size = AllIndexesRecursive(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 2, 2, 5}, x = 2;

    int n = sizeof(arr) / sizeof(arr[0]);

    AllIndexes(arr, n, x);

    return 0;
}
