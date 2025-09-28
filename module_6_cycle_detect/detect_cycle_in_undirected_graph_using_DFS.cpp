#include <bits/stdc++.h>;
using namespace std;

int vis[105];

vector<vector<int>> adj_list(105);
int parent[105];
bool cycle;

void BFS(int src)
{
    vis[src] = true;

    for (int child : adj_list[src])
    {
        if (vis[child] && parent[src] != child)
        {
            cycle = true;
        }
        else if (!vis[child])
        {
            parent[child] = src;
            BFS(child);
        }
    }
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
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            BFS(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << parent[i] << endl;
    }

    if (cycle)
        cout << "cycle detected";
    else
        cout << "cycle not detected";

    return 0;
}