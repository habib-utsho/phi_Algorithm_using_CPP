#include <bits/stdc++.h>;
using namespace std;

int vis[105];

vector<vector<int>> adj_list(105);
bool pathVis[105];
bool cycle;

void DFS(int src)
{
    vis[src] = true;
    pathVis[src] = true;

    for (int child : adj_list[src])
    {
        if (vis[child] && pathVis[child])
        {
            cycle = true;
        }
        else if (!vis[child])
        {
            DFS(child);
        }
    }

    pathVis[src] = false; // When backward the recursion then should path visit false
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i);
    }

    if (cycle)
        cout << "cycle detected";
    else
        cout << "cycle not detected";

    return 0;
}