#include <bits/stdc++.h>;
using namespace std;

bool visited[1005];

void DFS(int src, vector<vector<int>> adj_list, int compo, vector<int> &compoCountArr)
{
    // cout << src << endl;
    visited[src] = true;
    compoCountArr[compo]++;

    for (int child : adj_list[src])
    {
        if (!visited[child])
            DFS(child, adj_list, compo, compoCountArr);
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

    int compo = 0;
    vector<int> compoCountArr;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            compoCountArr.push_back(0);
            DFS(i, adj_list, compo, compoCountArr);
            compo++;
        }
    }

    sort(compoCountArr.begin(), compoCountArr.end());

    for (int val : compoCountArr)
    {
        cout << val << " ";
    }
    return 0;
}