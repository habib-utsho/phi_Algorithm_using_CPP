// https://codeforces.com/problemset/problem/2106/A

#include <bits/stdc++.h>;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string modifiedStr = str;
            modifiedStr[i] = modifiedStr[i] == '0' ? '1' : '0';
            // cout << modifiedStr << " ";
            v.push_back(modifiedStr);
        }
        int countOne = 0;
        for (string str : v)
        {
            for (char ch : str)
            {
                if (ch == '1')
                    countOne++;
            }
        }
        // cout << endl;
        cout << countOne << endl;
    }
    return 0;
}