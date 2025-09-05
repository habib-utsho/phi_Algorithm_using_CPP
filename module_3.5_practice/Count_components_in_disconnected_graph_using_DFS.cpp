#include <bits/stdc++.h>;
using namespace std;

bool visited[1005];
vector<int> adj_list[1005];

void DFS(int src)
{
    // cout << src << " ";
    visited[src] = true;
    for (int child : adj_list[src])
        if (!visited[child])
            DFS(child);
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

    memset(visited, false, sizeof(visited));

    int totalCompo = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            totalCompo++;
            DFS(i);
            cout << endl;
        }
    }

    cout << "Total compo: " << totalCompo << endl;

    return 0;
}