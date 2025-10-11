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
        vector<int> arr;

        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            int val;
            cin >> val;
            if (val < minVal)
                minVal = val;
            if (val > maxVal)
                maxVal = val;
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end());
        // for (int i = 0; i < size; i++)
        // {
        //     cout << " " << arr[i];
        // }

        if ((maxVal + minVal) % 2 == 0)
            // cout << "-> 0 Fashionable " << " ";
            cout << 0;
        else
        {
            int firstToLast = 0;
            int lastToFirst = 0;
            // Check first to last
            if (arr[0] % 2 == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] % 2 == 1 || i == size - 1)
                        break;
                    firstToLast++;
                }
            }
            else if (arr[0] % 2 == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    if (arr[i] % 2 == 0 || i == size - 1)
                        break;
                    firstToLast++;
                }
            }
            // Check last to first
            if (arr[size - 1] % 2 == 0)
            {
                for (int i = size - 1; i >= 0; i--)
                {
                    if (arr[i] % 2 == 1 || i == 0)
                        break;
                    lastToFirst++;
                }
            }
            else if (arr[size - 1] % 2 == 1)
            {
                for (int i = size - 1; i >= 0; i--)
                {
                    if (arr[i] % 2 == 0 || i == 0)
                        break;
                    lastToFirst++;
                }
            }

            int numOfMinOperation = min(firstToLast, lastToFirst);
            // cout << " " << firstToLast << " " << lastToFirst << " " << numOfMinOperation;
            cout << numOfMinOperation;
        }

        // cout << " ->" << minVal << " " << maxVal << endl;
        cout << endl;
    }

    return 0;
}