#include <bits/stdc++.h>;
using namespace std;

bool visited[1005];
int totalNodeVisit;

void DFS(int src, vector<vector<int>> adj_list)
{
    // cout << src << endl;
    visited[src] = true;
    totalNodeVisit++;

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
    int src;
    cin >> src;
    memset(visited, false, sizeof(visited));
    DFS(src, adj_list);

    cout << totalNodeVisit;
    return 0;
}