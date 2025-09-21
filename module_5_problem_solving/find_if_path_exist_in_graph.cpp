// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>;
using namespace std;

int n, e, source, dest;
vector<vector<int>> adj_list(200005);
bool visited[200005];

void DFS(int src)
{
    visited[src] = true;
    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            DFS(child);
        }
    }
}

int main()
{
    cin >> n >> e >> source >> dest;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " : " << " ";
    //     for (int val : adj_list[i])
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    memset(visited, false, sizeof(visited));
    DFS(source);

    if (visited[dest])
        cout << "true";
    else
        cout << "false";

    return 0;
}