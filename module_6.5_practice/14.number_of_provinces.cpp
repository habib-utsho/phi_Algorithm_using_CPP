// https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>;
using namespace std;

int n;
vector<vector<int>> isConnected;
vector<bool> vis;

void DFS(int node)
{
    vis[node] = true;

    for (int i = 0; i < isConnected[node].size(); i++)
    {

        if (!vis[i] && isConnected[node][i] == 1)
            DFS(i);
    }
}

int main()
{

    cin >> n;

    isConnected.assign(n, vector<int>(n));
    vis.assign(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> isConnected[i][j];

    int provincesCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFS(i);
            provincesCount++;
        }
        // cout << endl;
    }
    cout << provincesCount;
    return 0;
}