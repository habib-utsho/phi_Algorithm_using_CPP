#include <bits/stdc++.h>;
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> visit(1005, false);

// TC: O(N+E); or O(V+E)
// SC: O(N); or O(E)
// V means number of vertices, and e is the number of edges
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) // TC: O(N): or O(V)
    {
        // Taking front
        int par = q.front();
        q.pop();

        // work with target
        cout << par << " ";

        // Children push
        for (int child : adj_list[par]) // TC: O(E) ; E means edge
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

    int src, dest;
    cin >> src >> dest;

    bfs(src);
    cout << endl;
    if (visit[dest])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}