#include <bits/stdc++.h>;
using namespace std;

bool visited[1005];

void DFS(int src, vector<vector<int>> adj_list)
{
    // cout << src << endl;
    visited[src] = true;

    for (int child : adj_list[src])
    {
        if (!visited[child])
            DFS(child, adj_list);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(100);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    int totalCompo = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            totalCompo++;
            DFS(i, adj_list);
        }
    }

    cout << totalCompo;
    return 0;
}