// https://leetcode.com/problems/keys-and-rooms/description/
#include <bits/stdc++.h>;
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> visit(1005, false);

void DFS(int src)
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
        // cout << par << " ";

        // Children push
        for (int child : adj_list[par]) // TC: O(E) ; E means edge
        {
            // cout << "child: " << child << " ";
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
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    DFS(0);
    // cout << endl;

    bool allUnlocked = true;
    for (int i = 0; i < e; i++)
    {
        if (!visit[i])
        {
            allUnlocked = false;
            break;
        }
        // cout << i << ": " << visit[i] << " ";

        // cout << endl;
    }

    if (allUnlocked)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}