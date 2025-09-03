#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> adj_list, vector<bool> &visit, vector<int> &parentOfChild, vector<int> &level)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    level[src] = 1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << endl;

        // Children push
        for (int child : adj_list[parent])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[parent] + 1;
                parentOfChild[child] = parent;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(100005);
    vector<bool> visit(100005, false);
    vector<int> level(100005, -1);
    vector<int> parentOfChild(100005, -1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(1, adj_list, visit, parentOfChild, level);

    // cout << endl;

    // cout << e << " level is: " << level[e] << endl;
    if (level[n] != -1)
    {

        cout << level[n] << endl;

        int dest = n;
        vector<int> shortestPath;
        while (dest != -1)
        {
            shortestPath.push_back(dest);
            dest = parentOfChild[dest];
        }
        reverse(shortestPath.begin(), shortestPath.end());
        for (int val : shortestPath)
        {
            cout << val << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}