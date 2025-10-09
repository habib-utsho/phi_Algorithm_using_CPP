// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>;
using namespace std;
int v, e;
vector<vector<int>> adj_list(100005);
int vis[100005];
int parent[100005];
bool cycle;

void DFS(int src)
{
    vis[src] = true;

    for (int child : adj_list[src])
    {
        if (vis[child] && child != parent[src])
            cycle = true;
        if (!vis[child])
        {
            parent[child] = src;
            DFS(child);
        }
    }
}

int main()
{

    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle = false;

    for (int i = 0; i < v; i++)
        if (!vis[i])
            DFS(i);

    if (cycle)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";
    return 0;
}