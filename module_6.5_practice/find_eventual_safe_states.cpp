// https://leetcode.com/problems/find-eventual-safe-states/description/
#include <bits/stdc++.h>;
using namespace std;

int n, e;
vector<int> grid[10005];
bool vis[10005];
bool pathVis[10005];
vector<int> safeNodes;

bool DFS(int src)
{
    vis[src] = true;
    pathVis[src] = true;

    for (int child : grid[src])
    {
        if (vis[child] && pathVis[child])
        {
            return true;
        }

        if (!vis[child])
            if (DFS(child))
                return true;
    }

    safeNodes.push_back(src);
    pathVis[src] = false;
    return false;
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
    }

    // memset(safeNodes, -1, sizeof(safeNodes));

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " : ";
    //     for (int val : grid[i])
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i);
    }

    sort(safeNodes.begin(), safeNodes.end());
    for (int val : safeNodes)
    {
        cout << val << " ";
    }

    return 0;
}