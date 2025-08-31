#include <bits/stdc++.h>;
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> visit(1005, false);

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        // Taking front
        int par = q.front();
        q.pop();

        // work with target
        cout << par << " ";

        // Children push
        for (int child : adj_list[par])
        {
            // cout << child << " ";
            if (!visit[child])
            {
                visit[child] = true;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    // Getting input using adjacency list
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    // Output all
    // for (vector<int> v : adj_list)
    // {
    //     for (int val : v)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    bfs(0);

    return 0;
}