#include <bits/stdc++.h>;
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> visited(1005);

void DFS(int src) //TC: O(V+E)
{

    cout << src << " ";
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

    DFS(0);

    // for (int i = 0; i < 7; i++)
    // {
    //     cout << i << ": ";
    //     for (int val : adj_list[i])
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}