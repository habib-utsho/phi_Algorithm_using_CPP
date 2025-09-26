#include <bits/stdc++.h>;
using namespace std;

int vis[105];

vector<vector<int>> adj_list(105);
int parent[105];
bool cycle;

void DFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (vis[child] && child != parent[par])
            {
                cycle = true;
            }
            else if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
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
            DFS(i);
    }

    if (cycle)
        cout << "cycle detected";
    else
        cout << "cycle not detected";

    return 0;
}