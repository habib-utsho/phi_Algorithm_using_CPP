// https://leetcode.com/problems/find-eventual-safe-states/description/
#include <bits/stdc++.h>;
using namespace std;

int n, e;
vector<int> grid[10005];

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (int val : grid[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}