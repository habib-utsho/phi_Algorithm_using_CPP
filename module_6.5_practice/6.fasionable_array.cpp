// https://codeforces.com/problemset/problem/2110/A
#include <bits/stdc++.h>;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];

        for (int i = 0; i < size; i++)
            cin >> arr[i];
        sort(arr, arr + size);
        int minVal = arr[0];
        int maxVal = arr[size - 1];

        if (maxVal % 2 == minVal % 2)
            cout << 0;
        else
        {
            int i = 0, cnt1 = 0;
            while (arr[i] % 2 != maxVal % 2)
            {
                i++;
                cnt1++;
            }
            int j = size - 1, cnt2 = 0;
            while (arr[j] % 2 != minVal % 2)
            {
                j--;
                cnt2++;
            }

            int numOfMinOperation = min(cnt1, cnt2);
            // cout << " " << firstToLast << " " << lastToFirst << " " << numOfMinOperation;
            cout << numOfMinOperation;
        }

        // cout << " ->" << minVal << " " << maxVal << endl;
        cout << endl;
    }

    return 0;
}