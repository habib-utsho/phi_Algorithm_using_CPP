// https://leetcode.com/problems/keys-and-rooms/description/
#include <bits/stdc++.h>;
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> visit(1005, false);

void BFS(int src)
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

    return 0;
}